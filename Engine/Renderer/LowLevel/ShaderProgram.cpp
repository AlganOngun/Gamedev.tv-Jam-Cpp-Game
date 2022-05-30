#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "../../Utils/Exceptions/ShaderCompileErrorException.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace JamEngine
{
    void ShaderProgram::createProgram()
    {
        programId = glCreateProgram();
		std::cout << "Generated Shader Program" << std::endl;
    }

    void ShaderProgram::attachShader(const Shader& shader)
    {
        glAttachShader(programId, shader.getId());
    }

    void ShaderProgram::linkProgramAndCheckForErrors()
    {
        glLinkProgram(programId);
        checkForErrors();
    }

    void ShaderProgram::checkForErrors()
    {
        int success;
        char infoLog[512];
        glGetProgramiv(programId, GL_LINK_STATUS, &success);
        if(!success)
        {
			glGetProgramInfoLog(programId, 512, NULL, infoLog);
			std::cout << "ShaderLinkingError: " << infoLog << std::endl;
			throw Exceptions::ShaderCompileErrorException();
        }
    }

	void ShaderProgram::useProgram()
	{
		glUseProgram(programId);
	}

	void ShaderProgram::setMat4Uniform(std::string uniformName, glm::mat4 matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(programId, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void ShaderProgram::deleteProgram()
	{
		glDeleteProgram(programId);
	}

}
