#include "../Utils/enginePch.hpp"
#include "Window.hpp"

namespace JamEngine
{
	Window::Window(const std::string& title, int width, int height)
	{
		this->title = title;
		this->width = width;
		this->height = height;
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
		auto rawWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		glfwMakeContextCurrent(rawWindow);

		glfwWindow.reset(rawWindow);
	}

	void Window::initializeWindow()
	{
		glViewport(0, 0, width, height);
		isOpen = true;
	}

	void Window::update()
	{
		if(!isOpen) return;

		auto rawWindow = glfwWindow.release();

		glfwSwapBuffers(rawWindow);
		glfwPollEvents();

		if(glfwWindowShouldClose(rawWindow)) 
		{
			glfwWindow.reset(rawWindow);
			closeWindow();
		}
		glfwWindow.reset(rawWindow);
	}
}
