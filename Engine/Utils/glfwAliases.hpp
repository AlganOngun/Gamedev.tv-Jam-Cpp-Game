#pragma once

#include "enginePch.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
	struct glfwWindowDeleter
	{
		void operator()(GLFWwindow* window)
		{
			glfwDestroyWindow(window);
		}
	};

	using smartGlfwWindow = std::unique_ptr<GLFWwindow, glfwWindowDeleter>;
}
