#pragma once

#include "../../Utils/enginePch.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
	class EBO
	{
	private:
		std::vector<unsigned int> indices;
		unsigned int bufferId;
	public:
		EBO(const std::vector<unsigned int>& indices) : indices(indices) {}

		void generateBuffer();

		void initializeBuffer();

		void bindBuffer();

		void unbindBuffer();

		void deleteBuffer();
	};
}
