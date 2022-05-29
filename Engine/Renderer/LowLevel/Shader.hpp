#pragma once

#include "../../Utils/enginePch.hpp"

namespace JamEngine
{
    class Shader
    {
    private:
        unsigned int shaderId {};

        std::string shaderSource;

        void compileShader();
    public:
        Shader(std::string shaderFileName);
        void initializeShader(int shaderType);
        void createAndCompileShader();
		void deleteShader();

		unsigned int getId() const;
    };
}
