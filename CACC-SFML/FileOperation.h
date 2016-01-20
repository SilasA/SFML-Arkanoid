#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <string>
#include <fstream>


class FileOperation
{
public:

	unsigned int menuWinHeight, menuWinWidth, 
		windowWidth, windowHeight;

	int countBlocksX, countBlocksY;

	float ballRadius, ballVelocity,
		paddleWidth, paddleHeight, paddleVelocity,
		blockWidth, blockHeight,
		ftStep, ftSlice;

	void getData();

	FileOperation();
	~FileOperation();

private:

	std::ifstream *iFile;
	//std::ofstream *oFile;  For later implementation

	std::string findKeyword(const std::string &keyword);

};


#endif /* FILEOPERATION_H */