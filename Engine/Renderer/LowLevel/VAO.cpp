#include "VAO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace JamEngine
{
	void VAO::generate()
	{
		glGenVertexArrays(1, &arrayObjectId);
	}

	void VAO::bind()
	{
		glBindVertexArray(arrayObjectId);
	}

	void VAO::unbind()
	{
		glBindVertexArray(0);
	}

	void VAO::deleteObject()
	{
		glDeleteVertexArrays(1, &arrayObjectId);
	}
}
