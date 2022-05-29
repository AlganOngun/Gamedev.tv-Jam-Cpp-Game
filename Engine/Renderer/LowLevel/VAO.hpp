#pragma once

namespace JamEngine
{
	class VAO
	{
	private:
		unsigned int arrayObjectId {};
	public:
		void generate();
		void bind();	
		void unbind();	
		void deleteObject();
	};
}
