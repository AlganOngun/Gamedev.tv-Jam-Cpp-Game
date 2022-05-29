#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowMouseButtonReleasedEvent : public Event
	{
	private:
		int mouseButtonCode;
	public:
		WindowMouseButtonReleasedEvent(int mouseButtonCode) : mouseButtonCode(mouseButtonCode) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
