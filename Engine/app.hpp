#pragma once

#include "Renderer/Window.hpp"

namespace JamEngine
{
    class App
    {
	private:
		static Window window;

    public:
        static void initialize();
        static void update();
        static void end();

        virtual void start() = 0;
        virtual void run() = 0;
		virtual ~App() = 0;
    };
}
