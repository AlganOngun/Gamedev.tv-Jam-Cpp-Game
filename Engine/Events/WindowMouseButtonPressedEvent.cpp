#include "WindowMouseButtonPressedEvent.hpp"

namespace JamEngine
{
	std::string WindowMouseButtonPressedEvent::getStaticType()
	{
		return "TypeWindowMouseButtonPressedEvent";
	}

	std::string WindowMouseButtonPressedEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowMouseButtonPressedEvent::getInfo() const
	{
		return "WindowMouseButtonPressedEvent : mouseButtonCode: " + std::to_string(mouseButtonCode);
	}
}
