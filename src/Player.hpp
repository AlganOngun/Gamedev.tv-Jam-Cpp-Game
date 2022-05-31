#pragma once

#include "../Engine/include/JamEngine.hpp"
#include "Object.hpp"

class Player
{
private:
    JamEngine::Vector2F position {300.0f, 500.0f};

    Object playerObject = Object("../Shaders/defaultVertex.jmsh", "../Shaders/defaultFragment.jmsh",
                                 position, {50.0f, 50.0f}, 180.0f
                                );
public:
    Player();

    Object& getRenderable();

    void update();

	void OnInput(const JamEngine::WindowKeyPressedEvent& e);
};
