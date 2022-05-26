#pragma once

namespace JamEngine
{
	class Window;

    class App
    {
    public:
        static void initialize();
        static void end();

        virtual void start() = 0;
        virtual void run() = 0;
		virtual bool shouldEnd() = 0;
		virtual ~App() = 0;
    };
}
