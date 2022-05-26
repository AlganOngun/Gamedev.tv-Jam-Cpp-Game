#include "../Utils/enginePch.hpp"
#include "../Events/Event.hpp"
#include "../Events/WindowCloseEvent.hpp"
#include "Window.hpp"

namespace JamEngine
{
    Window::Window(const std::string& title, const Vector2& size)
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

        glClearColor(properties.color.r, properties.color.g, properties.color.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(rawWindow);
        glfwPollEvents();

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

        glfwWindow.reset(rawWindow);
    }

    Window::Window(const Window& window)
    {
        this->properties.size = window.properties.size;
        this->properties.title = window.properties.title;
    }
}
