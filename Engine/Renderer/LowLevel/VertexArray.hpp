#pragma once

#include "../../Utils/enginePch.hpp"

namespace JamEngine
{
	class VertexArray
	{
	private:
		std::vector<Vector2F> vertices{};
	public:
		void push(Vector2F vertexPosition);
		void pop();
		const Vector2F& getVertex(int index) const;
		Vector2F& getVertex(int index);
		
		const Vector2F& operator[](int) const;
		Vector2F& operator[](int);

		std::vector<float> parse();
	};
}
