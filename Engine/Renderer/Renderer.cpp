#include "../Utils/enginePch.hpp"
#include "LowLevel/VAO.hpp"
#include "LowLevel/VBO.hpp"
#include "LowLevel/EBO.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

#include "LowLevel/Shader.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace JamEngine
{
	void Renderer::initializeObject(Renderable& object) const
	{
        auto& objectProperties = object.getProperties();

		glm::mat4 projection = glm::ortho(0.0f, 600.0f, 600.0f, 0.0f, -1.0f, 1.0f);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(objectProperties.worldPosition.x, objectProperties.worldPosition.y, 0.0f));

        model = glm::rotate(model, glm::radians(objectProperties.rotation), glm::vec3(0.0f, 0.0f, 1.0f));

        model = glm::scale(model, glm::vec3(objectProperties.scale.x, objectProperties.scale.y, 1.0f));

		generateAndAttachShaders(object);

		VAO objectVao;
		objectVao.generate();
		objectVao.bind();

		generateVBO(object);
		generateEBO(object);

		objectProperties.shaderProgram.useProgram();
        objectProperties.shaderProgram.setMat4Uniform("model", model);
		objectProperties.shaderProgram.setMat4Uniform("projection", projection);
	}

	void Renderer::generateAndAttachShaders(Renderable& object) const
	{
        auto& objectProperties = object.getProperties();

        Shader vertexShader(objectProperties.vertexShaderPath);
        vertexShader.initializeShader(GL_VERTEX_SHADER);
        vertexShader.createAndCompileShader();

        Shader fragmentShader(objectProperties.fragmentShaderPath);
        fragmentShader.initializeShader(GL_FRAGMENT_SHADER);
        fragmentShader.createAndCompileShader();

        ShaderProgram& objectProgram = objectProperties.shaderProgram;
		objectProperties.shaderProgram.createProgram();
		objectProperties.shaderProgram.attachShader(vertexShader);
		objectProperties.shaderProgram.attachShader(fragmentShader);
		objectProperties.shaderProgram.linkProgramAndCheckForErrors();

        vertexShader.deleteShader();
        fragmentShader.deleteShader();
	}

	void Renderer::generateVBO(Renderable& object) const
	{
		auto& objectProperties = object.getProperties();

		VBO objectVbo(objectProperties.vertices);
		objectVbo.generateBuffer();

		objectVbo.bindBuffer();
		objectVbo.initializeBuffer();
		objectVbo.addVertexAttribute<float>(0, 3, GL_FLOAT, 0);
		objectVbo.enableVertexAttributes();
	}

	void Renderer::generateEBO(Renderable& object) const
	{
		auto& objectProperties = object.getProperties();

		EBO objectEbo(objectProperties.indices);
		objectEbo.generateBuffer();

		objectEbo.bindBuffer();
		objectEbo.initializeBuffer();
	}

    void Renderer::render() const
    {
        for(auto& object : objects)
        {
			initializeObject(object);
			renderObject(object);
        }
    }

    void Renderer::renderObject(Renderable& object) const
    {
		auto& objectProperties = object.getProperties();

		objectProperties.shaderProgram.useProgram();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		objectProperties.shaderProgram.deleteProgram();
    }
}
