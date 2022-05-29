#pragma once

#include "../Utils/enginePch.hpp"
#include "Event.hpp"

namespace JamEngine
{
    class WindowResizeEvent : public Event
	{
	private:
		Vector2I size{};
	public:
		WindowResizeEvent(Vector2I size) : size(size) {}

		static std::string getStaticType();
		std::string getRealType() const override;
		std::string getInfo() const override;
	};
}
