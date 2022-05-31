#include "WindowKeyPressedEvent.hpp"

namespace JamEngine
{
	std::string WindowKeyPressedEvent::getStaticType()
	{
		return "TypeWindowKeyPressedEvent";
	}

	std::string WindowKeyPressedEvent::getRealType() const
	{
		return getStaticType();
	}

	std::string WindowKeyPressedEvent::getInfo() const
	{
		return "WindowKeyPressedEvent : keyCode: " + std::to_string(keyCode);
	}

	int WindowKeyPressedEvent::getKeyCode() const
	{
		return keyCode;
	}
}
