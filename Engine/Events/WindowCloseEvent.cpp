#include "WindowCloseEvent.hpp"

namespace JamEngine
{
	std::string WindowCloseEvent::getStaticType()
	{
		return "TypeWindowCloseEvent";
	}

	std::string WindowCloseEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowCloseEvent::getInfo() const
	{
		return "WindowClosedEvent: Called";
	}
}
