#include "WindowCloseEvent.hpp"

namespace JamEngine
{
	std::string WindowCloseEvent::getStaticType()
	{
		return "TypeWindowCloseEvent";
	}

	std::string WindowCloseEvent::getRealType() const
	{
		return WindowCloseEvent::getStaticType();
	}

	std::string WindowCloseEvent::getInfo() const
	{
		return "WindowClosedEvent: Called";
	}
}
