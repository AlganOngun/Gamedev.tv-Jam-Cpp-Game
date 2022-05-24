#include <iostream>
#include <memory>
#include <JamEngine.hpp>

class JamGame : public JamEngine::App
{
public:
	void start()
	{
		JamEngine::App::initialize();
		std::cout << "Hello World";
	}

	void run()
	{
		JamEngine::App::update();
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

	while(1)
	{
		game->run();
	}
}
