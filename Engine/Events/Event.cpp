#include "Event.hpp"

namespace JamEngine
{
	std::string Event::getStaticType()
	{
		return "TypeDefaultEvent";
	}

	std::string Event::getRealType() const
	{
		return getStaticType();
	}
}
