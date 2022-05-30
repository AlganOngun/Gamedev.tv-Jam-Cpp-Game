#include "../Utils/enginePch.hpp"
#include "../Events/Event.hpp"
#include "../Events/WindowCloseEvent.hpp"
#include "../Events/WindowResizeEvent.hpp"
#include "../Events/WindowKeyPressedEvent.hpp"
#include "../Events/WindowKeyReleasedEvent.hpp"
#include "../Events/WindowCursorPositionEvent.hpp"
#include "../Events/WindowMouseButtonPressedEvent.hpp"
#include "../Events/WindowMouseButtonReleasedEvent.hpp"
#include "Window.hpp"
#include <GLFW/glfw3.h>

namespace JamEngine
{
    Window::Window(const std::string& title, const Vector2I& size)
    {
        this->properties.title = title;
        this->properties.size = size;
    }

    Window& Window::operator=(const Window& right)
    {
        this->properties.title = right.properties.title;
        this->properties.size = right.properties.size;

        return *this;
    }

    void Window::createWindow()
    {
        auto rawWindow = glfwCreateWindow(properties.size.x, properties.size.y, properties.title.c_str(), NULL, NULL);

        glfwMakeContextCurrent(rawWindow);

        glfwWindow.reset(rawWindow);

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glViewport(0, 0, properties.size.x, properties.size.y);
    }

    void Window::update()
    {
        auto rawWindow = glfwWindow.release();

		glfwSwapBuffers(rawWindow);
        glfwPollEvents();

        glClearColor(properties.color.r, properties.color.g, properties.color.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwWindow.reset(rawWindow);
    }

    void Window::changeColor(const Color& newColor)
    {
        this->properties.color = newColor;
    }

    void Window::setCallbackFunction(const eventCallbackFunction& callbackFunction)
    {
		properties.callbackFunction = callbackFunction;

        auto rawWindow = glfwWindow.release();

        glfwSetWindowUserPointer(rawWindow, &properties);

        glfwSetWindowCloseCallback(rawWindow, [](GLFWwindow * window)
        {
			auto properties = *(windowProperties*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			properties.callbackFunction(event);
        });

        glfwSetWindowSizeCallback(rawWindow, [](GLFWwindow * window, int width, int height)
        {
			auto properties = *(windowProperties*)glfwGetWindowUserPointer(window);

			properties.size = {width, height};

			glViewport(0, 0, width, height);

			WindowResizeEvent event({width, height});
			properties.callbackFunction(event);
        });

		glfwSetKeyCallback(rawWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
			auto properties = *(windowProperties*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    WindowKeyPressedEvent event(key);
                    properties.callbackFunction(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    WindowKeyReleasedEvent event(key);
                    properties.callbackFunction(event);
                    break;
                }
            }
        });

		glfwSetCursorPosCallback(rawWindow, [](GLFWwindow* window, double x, double y) 
		{
			auto properties = *(windowProperties*)glfwGetWindowUserPointer(window);

			WindowCursorPositionEvent event({x, y});
			properties.callbackFunction(event);
		});

		glfwSetMouseButtonCallback(rawWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto properties = *(windowProperties*)glfwGetWindowUserPointer(window);
			switch(action)
			{
				case GLFW_PRESS:
				{
					WindowMouseButtonPressedEvent event(button);
					properties.callbackFunction(event);
					break;
				}
				case GLFW_RELEASE:
				{
					WindowMouseButtonReleasedEvent event(button);
					properties.callbackFunction(event);
					break;
				}
			}
		});

        glfwWindow.reset(rawWindow);
    }

    Window::Window(const Window& window)
    {
        this->properties.size = window.properties.size;
        this->properties.title = window.properties.title;
    }
}
