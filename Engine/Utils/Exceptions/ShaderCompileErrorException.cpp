#include "ShaderCompileErrorException.hpp"

namespace JamEngine::Exceptions
{
	const char* ShaderCompileErrorException::what() const throw()
	{
		return "ShaderCompileErrorException was thrown. Check the console to see the error";
	}
}
