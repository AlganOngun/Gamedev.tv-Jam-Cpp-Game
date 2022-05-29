#include "WindowCursorPositionEvent.hpp"

namespace JamEngine
{
	std::string WindowCursorPositionEvent::getStaticType()
	{
		return "TypeWindowCursorPositionEvent";
	}

	std::string WindowCursorPositionEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowCursorPositionEvent::getInfo() const
	{
		return "WindowCursorPositionEvent: x: " + std::to_string(position.x) + " y: " + std::to_string(position.y);
	}
}
