#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowCursorPositionEvent : public Event
	{
	private:
		Vector2 position{};
	public:
		WindowCursorPositionEvent(const Vector2& position) : position(position) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
