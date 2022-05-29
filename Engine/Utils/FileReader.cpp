#include "FileReader.hpp"

namespace JamEngine
{
	FileReader::FileReader(const std::string& fileName)
	{
		file.open(fileName);
	}

	std::string FileReader::getFileContent()
	{
		std::stringstream stream;
		std::string line;	
		
		while(std::getline(file, line))
		{
			stream << line << '\n';
		}

		return stream.str();
	}

	FileReader::~FileReader()
	{
		file.close();
	}
}
