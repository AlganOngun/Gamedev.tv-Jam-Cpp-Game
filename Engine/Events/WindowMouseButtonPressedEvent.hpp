#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowMouseButtonPressedEvent : public Event
	{
	private:
		int mouseButtonCode;
	public:
		WindowMouseButtonPressedEvent(int mouseButtonCode) : mouseButtonCode(mouseButtonCode) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
