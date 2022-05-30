#include "../Utils/enginePch.hpp"
#include "LowLevel/VAO.hpp"
#include "LowLevel/VBO.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

#include "LowLevel/Shader.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace JamEngine
{
	void Renderer::initialize() const
	{
		for(auto& object : objects)
		{
			initializeObject(object);
		}
	}

	void Renderer::initializeObject(Renderable& object) const
	{
        auto objectProperties = object.getProperties();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(objectProperties.scale.x, objectProperties.scale.y, 0.0f));

        model = glm::rotate(model, glm::radians(objectProperties.rotation), glm::vec3(0.0f, 0.0f, 1.0f));

        model = glm::scale(model, glm::vec3(objectProperties.scale.x, objectProperties.scale.y, 1.0f));

		generateAndAttachShaders(object);

		VAO objectVao;
		objectVao.generate();
		objectVao.bind();

		VBO& objectVbo = generateVBO(object);

		objectVbo.deleteBuffer();
		
        objectProperties.shaderProgram.setMat4Uniform("model", model);
	}

	void Renderer::generateAndAttachShaders(Renderable& object) const
	{
        auto objectProperties = object.getProperties();

        Shader vertexShader(objectProperties.vertexShaderPath);
        vertexShader.initializeShader(GL_VERTEX_SHADER);
        vertexShader.createAndCompileShader();

        Shader fragmentShader(objectProperties.fragmentShaderPath);
        fragmentShader.initializeShader(GL_FRAGMENT_SHADER);
        fragmentShader.createAndCompileShader();

        ShaderProgram& objectProgram = objectProperties.shaderProgram;
        objectProgram.createProgram();
        objectProgram.attachShader(vertexShader);
        objectProgram.attachShader(fragmentShader);
        objectProgram.linkProgramAndCheckForErrors();

        vertexShader.deleteShader();
        fragmentShader.deleteShader();
	}

	VBO& Renderer::generateVBO(Renderable& object) const
	{
		auto objectProperties = object.getProperties();

		VBO vbo(objectProperties.vertices);
		vbo.generateBuffer();

		vbo.bindBuffer();
		vbo.initializeBuffer();

		vbo.addVertexAttribute<float>(0, 3, GL_FLOAT, 0);
		vbo.enableVertexAttributes();

		vbo.unbindBuffer();

		return vbo;
	}

    void Renderer::render() const
    {
        for(auto& object : objects)
        {
			renderObject(object);
        }
    }

    void Renderer::renderObject(Renderable& object) const
    {
		auto objectProperties = object.getProperties();

		glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}
