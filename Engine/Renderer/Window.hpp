#pragma once

#include "../Utils/enginePch.hpp"
#include "../Utils/glfwAliases.hpp"

namespace JamEngine
{
	class Event;

    class Window
    {
    private:

        using eventCallbackFunction = std::function<void(Event&)>;

        smartGlfwWindow glfwWindow;

        struct windowProperties
        {
            Vector2I size{};
            Color color{};
            std::string title{};

			eventCallbackFunction callbackFunction;
        };

		windowProperties properties;

    public:
        Window(const std::string& title, const Vector2I& size);
        Window& operator=(const Window& right);

        void createWindow();

        void changeColor(const Color& newColor);

        void setCallbackFunction(const eventCallbackFunction& callbackFunction);

        void update();

        Window(const Window& window);
    };
}
