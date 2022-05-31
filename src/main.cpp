#include <functional>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <memory>
#include "../Engine/include/JamEngine.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class JamGame : public JamEngine::App
{
private:
    bool isOpen = true;

    JamEngine::Window window = JamEngine::Window("Game", {600, 600});

	Player player;
public:

    void start()
    {
        JamEngine::App::initialize();

        window.createWindow();
        window.changeColor({ 0.0f, 0.0f, 0.0f });
        window.setCallbackFunction(std::bind(&JamGame::OnWindowEvent, this, std::placeholders::_1));
    }

    void run()
    {
		player.update();

		std::vector<std::reference_wrapper<JamEngine::Renderable>> objects;

		objects.push_back(player.getRenderable());

		JamEngine::Renderer renderer(objects);
	
        renderer.render();

        window.update();
    }

    void OnWindowEvent(const JamEngine::Event& e)
    {
        std::cout << e.getInfo() << std::endl;
        JamEngine::EventDispatcher dispatcher;
        dispatcher.dispatch<JamEngine::WindowCloseEvent>(e, std::bind(&JamGame::OnWindowCloseEvent, this, std::placeholders::_1));
        dispatcher.dispatch<JamEngine::WindowKeyPressedEvent>(e, std::bind(&Player::OnInput, &player, std::placeholders::_1));
    }

    void OnWindowCloseEvent(const JamEngine::WindowCloseEvent& e)
    {
        isOpen = false;
    }

    bool shouldEnd()
    {
        return !isOpen;
    }

    void end()
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
    game->end();
}
