#pragma once

#include <exception>

namespace JamEngine::Exceptions
{
	class ShaderCompileErrorException : public std::exception
	{
	public:
		const char* what() const throw();
	};
}
