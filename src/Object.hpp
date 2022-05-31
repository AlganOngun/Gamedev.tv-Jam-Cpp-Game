#pragma once

#include "../Engine/include/JamEngine.hpp"

class Object : public JamEngine::Renderable
{
private:
	JamEngine::renderableProperties properties {};
public:
	Object(std::string vertexShaderPath, std::string fragmentShaderPath, JamEngine::Vector2F worldPosition, JamEngine::Vector2F scale, float rotation);

	void setVertices(const JamEngine::VertexArray& vertices);

	void setIndices(const std::vector<unsigned int>& indices);

	void setPosition(const JamEngine::Vector2F& position);

	JamEngine::renderableProperties& getProperties() override;
};
