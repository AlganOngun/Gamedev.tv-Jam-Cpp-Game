#pragma once

#include "enginePch.hpp"

namespace JamEngine
{
    class FileReader
    {
    private:
		std::ifstream file;
	public:
        FileReader(const std::string& fileName);
        ~FileReader();

        std::string getFileContent();
    };
}
