#pragma once

#include "../Utils/enginePch.hpp"
#include "../Utils/glfwAliases.hpp"

namespace JamEngine
{
    class Window
    {
	private:
		smartGlfwWindow glfwWindow;

		Vector2 size;
		std::string title{};
		bool isOpen = false;

		void closeWindow();

	public:
		Window(const std::string& title, const Vector2& size);
		~Window();

		void createWindow();
		void initializeWindow();

		void update();

		bool isWindowOpen();
    };
}
