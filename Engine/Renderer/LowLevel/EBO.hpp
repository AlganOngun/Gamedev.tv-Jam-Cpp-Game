#pragma once

#include "../../Utils/enginePch.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
	template <unsigned int size>
	class EBO
	{
	private:
		std::array<unsigned int, size> indices;
		unsigned int bufferId;
	public:
		EBO(const std::array<unsigned int, size> indices) : indices(indices) {}

		void generateBuffer()
		{
			glGenBuffers(1, &bufferId);
		}

		void initializeBuffer()
		{
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW); 
		}

		void bindBuffer()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
		}

		void unbindBuffer()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void deleteBuffer()
		{
			glDeleteBuffers(1, &bufferId);
		}
	};
}
