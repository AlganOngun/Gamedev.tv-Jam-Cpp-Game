#include "VertexArray.hpp"

namespace JamEngine
{
	void VertexArray::push(Vector2F vertexPosition)
	{
		vertices.push_back(vertexPosition);
	}

	void VertexArray::pop()
	{
		vertices.pop_back();
	}

	std::vector<float> VertexArray::parse()
	{
		std::vector<float> parsedVector{};

		for(auto& vertex : vertices)
		{
			parsedVector.push_back(vertex.x);
			parsedVector.push_back(vertex.y);
			parsedVector.push_back(0.0f);
		}

		return parsedVector;
	}

	const Vector2F& VertexArray::getVertex(int index) const
	{
		return vertices[index];
	}

	Vector2F& VertexArray::getVertex(int index)
	{
		return vertices[index];
	}

	const Vector2F& VertexArray::operator[](int index) const
	{
		const Vector2F& element {getVertex(index)};
		return element;
	}

	Vector2F& VertexArray::operator[](int index)
	{
		Vector2F& element {getVertex(index)};
		return element;
	}
}
