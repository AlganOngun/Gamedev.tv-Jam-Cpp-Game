#include "../Utils/enginePch.hpp"
#include "Window.hpp"

namespace JamEngine
{
	Window::Window(const std::string& title, const Vector2& size)
	{
		this->title = title;
		this->size = size;
	}

	Window::~Window()
	{
		closeWindow();
	}

	void Window::closeWindow()
	{
		isOpen = false;
	}

	void Window::createWindow()
	{
		auto rawWindow = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);

		glfwMakeContextCurrent(rawWindow);

		glfwWindow.reset(rawWindow);
	}

	void Window::initializeWindow()
	{
		glViewport(0, 0, size.x, size.y);
		isOpen = true;
	}

	void Window::update()
	{
		if(!isOpen) return;

		auto rawWindow = glfwWindow.release();

		glClearColor(color.r, color.g, color.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(rawWindow);
		glfwPollEvents();

		if(glfwWindowShouldClose(rawWindow)) 
		{
			glfwWindow.reset(rawWindow);
			closeWindow();
		}
		glfwWindow.reset(rawWindow);
	}

	bool Window::isWindowOpen()
	{
		return isOpen;
	}

	void Window::changeColor(Color newColor)
	{
		this->color = newColor;
	}
}
