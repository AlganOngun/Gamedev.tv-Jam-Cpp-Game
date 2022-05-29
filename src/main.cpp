#include <functional>
#include <iostream>
#include <memory>
#include "../Engine/include/JamEngine.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class JamGame : public JamEngine::App
{
private:
	bool isOpen = true;

	JamEngine::Window window = JamEngine::Window("Game", {600, 600});
	JamEngine::ShaderProgram program;
	JamEngine::VAO vao;
public:

	void start()
	{
		JamEngine::App::initialize();

		window.createWindow();
		window.changeColor({1.0f, 0.0f, 0.0f});
		window.setCallbackFunction(std::bind(&JamGame::OnWindowEvent, this, std::placeholders::_1));


		JamEngine::Shader vertexShader("../Shaders/testVertex.jmsh");
		vertexShader.initializeShader(GL_VERTEX_SHADER);
		vertexShader.createAndCompileShader();

		JamEngine::Shader fragmentShader("../Shaders/testFragment.jmsh");
		fragmentShader.initializeShader(GL_FRAGMENT_SHADER);
		fragmentShader.createAndCompileShader();

		program.createProgram();

		program.attachShader(vertexShader);
		program.attachShader(fragmentShader);
		program.linkProgramAndCheckForErrors();

		vertexShader.deleteShader();
		fragmentShader.deleteShader();

		JamEngine::VertexArray vertices;
		vertices.push({-0.5f, -0.5f});
		vertices.push({0.5f, -0.5f});
		vertices.push({0.0f,  0.5f});

		JamEngine::VBO vbo(vertices);
		vao.generate();
		vbo.generateBuffer();

		vao.bind();
		
		vbo.bindBuffer();
		vbo.initializeBuffer();

		vbo.addVertexAttribute<float>(0, 3, GL_FLOAT, 0);
		vbo.enableVertexAttributes();

		vbo.unbindBuffer();
		vao.unbind();

		vbo.deleteBuffer();
	}

	void run()
	{
		program.useProgram();
		vao.bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

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
		vao.deleteObject();
		program.deleteProgram();
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
