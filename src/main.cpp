#include <iostream>
#include <memory>
#include <JamEngine.hpp>

class JamGame : public JamEngine::App
{
public:
	void start()
	{
		JamEngine::App::initialize();
	}

	void run()
	{
		JamEngine::App::update();
	}

	bool shouldEnd()
	{
		return !JamEngine::App::isOpen;
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
