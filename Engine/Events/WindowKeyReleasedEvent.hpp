#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowKeyReleasedEvent : public Event
	{
	private:
		int keyCode;
	public:
		WindowKeyReleasedEvent(int keyCode) : keyCode(keyCode) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
