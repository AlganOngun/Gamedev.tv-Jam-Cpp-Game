#pragma once

#include "../Utils/enginePch.hpp"

namespace JamEngine
{
    class Event
    {
    public:
        static std::string getStaticType();
		virtual std::string getInfo() const = 0;
		virtual std::string getRealType() const;
    };
}
