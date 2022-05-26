#include <functional>
#include <iostream>
#include <memory>
#include <JamEngine.hpp>

class JamGame : public JamEngine::App
{
private:
	bool isOpen = true;

	JamEngine::Window window = JamEngine::Window("Game", {600, 600});
public:

	void start()
	{
		JamEngine::App::initialize();

		window.createWindow();
		window.setCallbackFunction(std::bind(&JamGame::OnWindowEvent, this, std::placeholders::_1));
	}

	void run()
	{
		window.update();
	}

	void OnWindowEvent(const JamEngine::Event& e)
	{
		JamEngine::EventDispatcher dispatcher;
		dispatcher.dispatch<JamEngine::WindowCloseEvent>(e, std::bind(&JamGame::OnWindowCloseEvent, this, std::placeholders::_1));
	}

	void OnWindowCloseEvent(const JamEngine::WindowCloseEvent& e)
	{
		isOpen = false;
	}

	bool shouldEnd()
	{
		return !isOpen;
	}

	~JamGame()
	{
		JamEngine::App::end();
	}
};

int main()
{
	auto game = std::make_unique<JamGame>(JamGame());
	game->start();

	while(!game->shouldEnd())
	{
		game->run();
	}
}
