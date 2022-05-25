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
		Color color;
		std::string title{};
		bool isOpen = false;

		void closeWindow();

	public:
		Window(const std::string& title, const Vector2& size);
		Window& operator=(const Window& right);
		~Window();

		void createWindow();

		void changeColor(const Color& newColor);

		void update();

		bool isWindowOpen();

		Window(const Window& window);
	};
}
