#pragma once

#include "../Utils/enginePch.hpp"
#include "LowLevel/ShaderProgram.hpp"
#include "LowLevel/VertexArray.hpp"

namespace JamEngine
{
	struct renderableProperties
	{
		Vector2F worldPosition;
		Vector2F scale;
		float rotation;

		std::string vertexShaderPath, fragmentShaderPath;

		VertexArray vertices;
		std::vector<unsigned int> indices;

		ShaderProgram shaderProgram;
	};

	class Renderable
	{
	public:
		virtual renderableProperties& getProperties() const = 0;
	};
}
