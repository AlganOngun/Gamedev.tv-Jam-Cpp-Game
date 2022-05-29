#include "VertexArray.hpp"
#include "VBO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
	VBO::VBO(const VertexArray& vertices)
	{
		this->vertices = vertices;
	}

	void VBO::generateBuffer()
	{
		glGenBuffers(1, &bufferId);
	}

	void VBO::bindBuffer()
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	}

	void VBO::unbindBuffer()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::initializeBuffer()
	{
		glBufferData(GL_ARRAY_BUFFER, vertices.parse().size() * sizeof(float), vertices.parse().data(), GL_STATIC_DRAW);
	}

	void VBO::enableVertexAttributes()
	{
		glEnableVertexAttribArray(0);
	}

	void VBO::deleteBuffer()
	{
		glDeleteBuffers(1, &bufferId);
	}
}
