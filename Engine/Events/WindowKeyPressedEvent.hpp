#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowKeyPressedEvent : public Event
	{
	private:
		int keyCode;
	public:
		WindowKeyPressedEvent(int keyCode) : keyCode(keyCode) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
