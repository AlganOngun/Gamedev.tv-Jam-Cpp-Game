#pragma once

#include "../Utils/enginePch.hpp"
#include "../Utils/glfwAliases.hpp"

namespace JamEngine
{
    class Window
    {
	private:
		smartGlfwWindow glfwWindow;

		int width{}, height{};
		std::string title{};
		bool isOpen = false;

		void closeWindow();

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		void createWindow();
		void initializeWindow();

		void update();
    };
}
