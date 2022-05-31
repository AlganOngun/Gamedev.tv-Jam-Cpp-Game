#include <functional>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <memory>
#include "../Engine/include/JamEngine.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Square : public JamEngine::Renderable
{
private:
	JamEngine::renderableProperties properties {};
public:
	Square(std::string vertexShaderPath, std::string fragmentShaderPath, JamEngine::Vector2F worldPosition, JamEngine::Vector2F scale, float rotation)
	{
		properties.vertexShaderPath = vertexShaderPath;
		properties.fragmentShaderPath = fragmentShaderPath;
		properties.rotation = rotation;
		properties.scale = scale;
		properties.worldPosition = worldPosition;
	}

	void setVertices(JamEngine::VertexArray vertices)
	{
		properties.vertices = vertices;
	}

	void setIndices(const std::vector<unsigned int>& indices)
	{
		properties.indices = indices;
	}

	JamEngine::renderableProperties& getProperties() override
	{
		return properties;
	}
};

class JamGame : public JamEngine::App
{
private:
    bool isOpen = true;

    JamEngine::Window window = JamEngine::Window("Game", {600, 600});
	Square mySquare = Square("../Shaders/spriteVertex.jmsh", "../Shaders/spriteFragment.jmsh", {300.0f, 300.0f}, {150.0f, 150.0f}, 45.0f);
	Square anotherSquare = Square("../Shaders/spriteVertex.jmsh", "../Shaders/spriteFragment.jmsh", {0.0f, 0.0f}, {150.0f, 150.0f}, 0.0f);
	std::vector<std::reference_wrapper<JamEngine::Renderable>> objects;
	std::unique_ptr<JamEngine::Renderer> renderer;
public:

    void start()
	{
		JamEngine::App::initialize();

		window.createWindow();
		window.changeColor({ 0.0f, 0.0f, 0.0f });
		window.setCallbackFunction(std::bind(&JamGame::OnWindowEvent, this, std::placeholders::_1));

		JamEngine::VertexArray vertices;
		vertices.push({ 0.5f, 0.5f });
		vertices.push({ 0.5f, -0.5f });
		vertices.push({ -0.5f, -0.5f });
		vertices.push({ -0.5f, 0.5f });

		std::vector<unsigned int> indices = 
		{
			0, 1, 3,
			1, 2, 3
		};

		std::vector<unsigned int> secondIndices = 
		{
			0, 1, 3
		};

		mySquare.setVertices(vertices);
		anotherSquare.setVertices(vertices);

		mySquare.setIndices(secondIndices);
		anotherSquare.setIndices(indices);

		objects.push_back(anotherSquare);
		objects.push_back(mySquare);

		renderer = std::make_unique<JamEngine::Renderer>(JamEngine::Renderer(objects));
	}

    void run()
    {
		renderer->render();

        window.update();
    }

    void OnWindowEvent(const JamEngine::Event& e)
    {
        std::cout << e.getInfo() << std::endl;
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
