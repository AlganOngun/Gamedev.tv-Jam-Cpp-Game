#include <iostream>
#include <memory>
#include <JamEngine.hpp>

class JamGame : public JamEngine::App
{
private:
	bool isOpen = false;

	JamEngine::Window window = JamEngine::Window("Game", {600, 600});
public:

	void start()
	{
		JamEngine::App::initialize();

		window.createWindow();
		window.initializeWindow();

		isOpen = window.isWindowOpen();
	}

	void run()
	{
		window.update();
		isOpen = window.isWindowOpen();
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
