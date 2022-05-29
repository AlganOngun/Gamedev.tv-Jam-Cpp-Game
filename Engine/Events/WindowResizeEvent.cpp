#include "WindowResizeEvent.hpp"

namespace JamEngine
{
	std::string WindowResizeEvent::getStaticType()
	{
		return "TypeWindowResizeEvent";
	}

	std::string WindowResizeEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowResizeEvent::getInfo() const
	{
		return "WindowResizeEvent: width: " + std::to_string(size.x) + " height: " + std::to_string(size.y);
	}
}
