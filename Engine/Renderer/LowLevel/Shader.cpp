#include "Shader.hpp"
#include "../../Utils/FileReader.hpp"
#include "../../Utils/Exceptions/ShaderCompileErrorException.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JamEngine
{
    Shader::Shader(std::string shaderFileName)
    {
        FileReader reader(shaderFileName);
        shaderSource = reader.getFileContent();
    }

    void Shader::initializeShader(int shaderType)
    {
        shaderId = glCreateShader(shaderType);
    }

    void Shader::createAndCompileShader()
    {
        const char* sourceData = shaderSource.data();
        glShaderSource(shaderId, 1, &sourceData, NULL);
        compileShader();
    }

    void Shader::compileShader()
    {
        glCompileShader(shaderId);

        int success;
        char infoLog[512];
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if(!success)
        {  
			glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            std::cout << "Error: Shader Compilation Error: " << infoLog << std::endl;
            throw Exceptions::ShaderCompileErrorException();
        }
    }

	void Shader::deleteShader()
	{
		glDeleteShader(shaderId);
	}

	unsigned int Shader::getId() const
	{
		return shaderId;
	}
}
