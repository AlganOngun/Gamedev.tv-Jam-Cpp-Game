#include "Renderer/Window.hpp"
#include "app.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace JamEngine
{
	Window App::window("Jam Game", {600, 600});
	bool App::isOpen = false;

    void App::initialize()
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window.createWindow();

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		window.initializeWindow();

		isOpen = true;
    }

    void App::update()
    {
		window.update();
		isOpen = window.isWindowOpen();
    }

    void App::end()
    {
		glfwTerminate();
    }

	App::~App()
	{
		end();
	}
}
