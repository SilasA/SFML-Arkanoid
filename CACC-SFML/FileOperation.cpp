#include "FileOperation.h"

#include <string>

FileOperation::FileOperation()
{
	this->iFile = new std::ifstream();
	try
	{
		this->iFile->open("config.txt");
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}


FileOperation::~FileOperation()
{
	this->iFile->close();
	delete this->iFile;
}


void FileOperation::getData()
{
	menuWinHeight = std::stoi(findKeyword("menuWinHeight"));

	return;
}


std::string FileOperation::findKeyword(const std::string &keyword)
{
	std::string line;
	std::string key;
	std::string value;
	int length = keyword.length;

	while (std::getline(*iFile, line))
	{
		key = line.substr(0, length - 1);
		if (key == keyword)
			value = line.substr(length + 1, line.length - 1);
	}
	return value;
}