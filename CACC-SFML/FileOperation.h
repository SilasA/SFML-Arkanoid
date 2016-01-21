#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <string>
#include <fstream>

// Gathers and stores config information for the game/application.
class FileOperation
{
public:

	// Config file variables 
	// Window dimensions
	unsigned int menuWinHeight, menuWinWidth, 
		windowWidth, windowHeight;

	// Block count
	int countBlocksX, countBlocksY;

	// Object dimensions
	float ballRadius, ballVelocity,
		paddleWidth, paddleHeight, paddleVelocity,
		blockWidth, blockHeight,
		ftStep, ftSlice;

	// Collects data from a file and puts the data into the apropriate variables
	void getData();

	// Opens the file
	FileOperation();

	// Deletes the file object
	~FileOperation();

private:

	// Reading the config data
	std::ifstream *iFile;
	//std::ofstream *oFile;  For later implementation

	// Takes a keyword and searches the file for the data that is bound via "="
	// in the file
	// Param keyword: The keyword for the method to find
	// Returns: The data bound to the keyword in string form
	std::string findKeyword(const std::string &keyword);

}dat;


#endif /* FILEOPERATION_H */