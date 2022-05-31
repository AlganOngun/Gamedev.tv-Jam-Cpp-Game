#pragma once

#include "../Utils/enginePch.hpp"
#include <functional>

namespace JamEngine
{
    class Renderable;
	class VBO;
	class VAO;

    class Renderer
    {
	private:
		const std::vector<std::reference_wrapper<Renderable>>& objects;

		void initializeObject(Renderable& object) const;

		void renderObject(Renderable& object) const;
		void generateAndAttachShaders(Renderable& object) const;
		void generateVBO(Renderable& object) const;
		void generateEBO(Renderable& object) const;
	public:
		Renderer(const std::vector<std::reference_wrapper<Renderable>>& objects) : objects(objects) {}
        void render() const;
    };
}
