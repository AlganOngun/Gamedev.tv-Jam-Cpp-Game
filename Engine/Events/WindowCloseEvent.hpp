#pragma once

#include "Event.hpp"

namespace JamEngine
{
    class WindowCloseEvent : public Event
	{
	public:
		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
