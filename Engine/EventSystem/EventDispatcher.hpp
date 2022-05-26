#pragma once
#include <iostream>

#include "../Events/Event.hpp"

namespace JamEngine
{
	class EventDispatcher
	{
	private:
		template<typename T>
		using expectedCallbackFunctionPattern = std::function<void(T&)>;

	public:
		template<typename T>
		inline void dispatch(const Event& event, const expectedCallbackFunctionPattern<T>& callbackFunction)
		{
			if(event.getRealType() == T::getStaticType())
			{
				Event& removedConst = const_cast<Event&>(event);
				T castedEvent = dynamic_cast<T&>(removedConst);
				callbackFunction(castedEvent);
			}
		}
	};
}
