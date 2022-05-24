#pragma once

#include "Renderer/Window.hpp"

namespace JamEngine
{
    class App
    {
	protected:
		static Window window;

    public:
        static void initialize();
        static void update();
        static void end();

        virtual void start() = 0;
        virtual void run() = 0;
		virtual bool shouldEnd() = 0;
		virtual ~App() = 0;
    };
}
