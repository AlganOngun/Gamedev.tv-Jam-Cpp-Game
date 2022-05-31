#include "Player.hpp"
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Player::Player()
{
    JamEngine::VertexArray vertices;
    vertices.push({ -0.5f, -0.5f });
    vertices.push({ 0.0f, 0.2f });
    vertices.push({ 0.5f, -0.5f });

    std::vector<unsigned int> indices =
    {
        0, 1, 2
    };

    playerObject.setVertices(vertices);
    playerObject.setIndices(indices);
}

Object& Player::getRenderable()
{
    return playerObject;
}

void Player::OnInput(const JamEngine::WindowKeyPressedEvent& e)
{
	int keyCode = e.getKeyCode();

	switch(keyCode)
	{
		case GLFW_KEY_RIGHT:
		{
			position.x+=5;
			break;
		}
		case GLFW_KEY_LEFT:
		{
			position.x-=5;
			break;
		}
	}
}

void Player::update()
{
    playerObject.setPosition(position);
}
