#include "WindowKeyReleasedEvent.hpp"

namespace JamEngine
{
	std::string WindowKeyReleasedEvent::getStaticType()
	{
		return "TypeWindowKeyReleasedEvent";
	}

	std::string WindowKeyReleasedEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowKeyReleasedEvent::getInfo() const
	{
		return "WindowKeyReleasedEvent : keyCode: " + std::to_string(keyCode);
	}
}
