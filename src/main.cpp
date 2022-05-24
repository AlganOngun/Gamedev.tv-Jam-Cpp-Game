#include <iostream>
#include <memory>
#include <JamEngine.hpp>

class JamGame : public JamEngine::App
{
private:
	bool isOpen = false;
public:
	void start()
	{
		JamEngine::App::initialize();
		isOpen = JamEngine::App::window.isWindowOpen();

		JamEngine::Color color {0.2f, 0.3f, 0.3f};
		JamEngine::App::window.changeColor(color);
	}

	void run()
	{
		JamEngine::App::update();
		isOpen = JamEngine::App::window.isWindowOpen();
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
