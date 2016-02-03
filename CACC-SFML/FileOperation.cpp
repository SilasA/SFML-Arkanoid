#include "stdafx.h"
#include "FileOperation.h"

#include <string>


FileOperation::FileOperation()
{
}


FileOperation::~FileOperation()
{
}


void FileOperation::openFile()
{
	iFile = new std::ifstream();
	try
	{
		iFile->open("config.txt");
		if (iFile->is_open())
			std::cout << "loaded config.txt" << std::endl;
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	getData();
}


void FileOperation::getData()
{
	// Int
	menuWinHeight =		std::stoi(findKeyword("menuWinHeight"));
	menuWinWidth =		std::stoi(findKeyword("menuWinWidth"));
	windowWidth =		std::stoi(findKeyword("windowHeight"));
	windowHeight =		std::stoi(findKeyword("windowWidth"));
	countBlocksX =		std::stoi(findKeyword("countBlocksX"));
	countBlocksY =		std::stoi(findKeyword("countBlocksY"));

	// Float
	ballRadius =		std::stof(findKeyword("ballRadius"));
	ballVelocity =		std::stof(findKeyword("ballVelocity"));
	paddleWidth =		std::stof(findKeyword("paddleWidth"));
	paddleHeight =		std::stof(findKeyword("paddleHeight"));
	paddleVelocity =	std::stof(findKeyword("paddleVelocity"));
	blockWidth =		std::stof(findKeyword("blockWidth"));
	blockHeight =		std::stof(findKeyword("blockHeight"));
	ftStep =			std::stof(findKeyword("ftStep"));
	ftSlice =			std::stof(findKeyword("ftSlice"));

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
		key = line.substr(0, length);
		if (key == keyword)
		{
			value = line.substr(length + 1, line.length() - 1);
			break;
		}
	}
	return value;
}