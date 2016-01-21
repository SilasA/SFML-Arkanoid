#include "stdafx.h"
#include "FileOperation.h"

#include <string>

FileOperation::FileOperation()
{
	this->iFile = new std::ifstream();
	try
	{
		this->iFile->open("config.txt");
		if (this->iFile->is_open())
			std::cout << "loaded config.txt" << std::endl;
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}


FileOperation::~FileOperation()
{
	delete this->iFile;
}


void FileOperation::getData()
{
	// Int
	menuWinHeight = std::stoi(findKeyword("menuWinHeight"));
	menuWinHeight = std::stoi(findKeyword("menuWinWidth"));
	menuWinHeight = std::stoi(findKeyword("windowHeight"));
	menuWinHeight = std::stoi(findKeyword("windowWidth"));
	menuWinHeight = std::stoi(findKeyword("countBlocksX"));
	menuWinHeight = std::stoi(findKeyword("countBlocksY"));

	// Float
	menuWinHeight = std::stof(findKeyword("ballRadius"));
	menuWinHeight = std::stof(findKeyword("ballVelocity"));
	menuWinHeight = std::stof(findKeyword("paddleWidth"));
	menuWinHeight = std::stof(findKeyword("paddleHeight"));
	menuWinHeight = std::stof(findKeyword("paddleVelocity"));
	menuWinHeight = std::stof(findKeyword("blockWidth"));
	menuWinHeight = std::stof(findKeyword("blockHeight"));
	menuWinHeight = std::stof(findKeyword("ftStep"));
	menuWinHeight = std::stof(findKeyword("ftSlice"));

	iFile->close();

	return;
}


std::string FileOperation::findKeyword(const std::string &keyword)
{
	std::string line;
	std::string key;
	std::string value;
	int length = keyword.length();

	while (std::getline(*iFile, line))
	{
		key = line.substr(0, length - 1);
		if (key == keyword)
		{
			value = line.substr(length + 1, line.length() - 1);
			break;
		}
	}
	return value;
}