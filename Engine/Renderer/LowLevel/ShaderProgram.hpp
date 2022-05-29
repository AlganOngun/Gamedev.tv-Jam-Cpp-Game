#pragma once

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
	};
}
