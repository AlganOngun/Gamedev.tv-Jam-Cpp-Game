#include "WindowMouseButtonReleasedEvent.hpp"

namespace JamEngine
{
	std::string WindowMouseButtonReleasedEvent::getStaticType()
	{
		return "TypeWindowMouseButtonReleasedEvent";
	}

	std::string WindowMouseButtonReleasedEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowMouseButtonReleasedEvent::getInfo() const
	{
		return "WindowMouseButtonReleasedEvent : mouseButtonCode: " + std::to_string(mouseButtonCode);
	}
}
