#pragma once

#include "../../Utils/enginePch.hpp"
#include <glm/glm.hpp>

namespace JamEngine
{
	class Shader;

	class ShaderProgram
	{
	private:
		unsigned int programId {};

		void checkForErrors();
	public:
		void createProgram();
		void attachShader(const Shader& shader);
		void linkProgramAndCheckForErrors();
		void useProgram();
		void deleteProgram();
		
		void setMat4Uniform(std::string uniformName, glm::mat4 matrix);
	};
}
