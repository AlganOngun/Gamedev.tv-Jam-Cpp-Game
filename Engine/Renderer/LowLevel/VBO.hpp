#pragma once

#include "VertexArray.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
	class VBO
	{
	private:
		GLuint bufferId {};
		VertexArray vertices;
	public:
		VBO(const VertexArray& vertices);
		void generateBuffer();
		void bindBuffer();
		void unbindBuffer();
		void initializeBuffer();
		void deleteBuffer();

		template<typename T>
		void addVertexAttribute(int layout, int attributeSize, GLenum dataType, int offset)
		{
			glVertexAttribPointer(layout, attributeSize, dataType, GL_FALSE, attributeSize * sizeof(T), (void*)offset);
		}

		void enableVertexAttributes();
	};
}
