#include "Object.hpp"

Object::Object(std::string vertexShaderPath, std::string fragmentShaderPath, JamEngine::Vector2F worldPosition, JamEngine::Vector2F scale, float rotation)
{
    properties.vertexShaderPath = vertexShaderPath;
    properties.fragmentShaderPath = fragmentShaderPath;
    properties.rotation = rotation;
    properties.scale = scale;
    properties.worldPosition = worldPosition;
}

void Object::setVertices(const JamEngine::VertexArray& vertices)
{
    properties.vertices = vertices;
}

void Object::setIndices(const std::vector<unsigned int>& indices)
{
    properties.indices = indices;
}

void Object::setPosition(const JamEngine::Vector2F& position)
{
	properties.worldPosition = position;
}

JamEngine::renderableProperties& Object::getProperties()
{
    return properties;
}
