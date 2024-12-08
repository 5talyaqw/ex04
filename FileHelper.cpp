#include "fileHelper.h"
#include <iostream>
#include <fstream>

std::string FileHelper::readFileToString(const std::string& fileName)
{
	std::ifstream file(fileName);
	std::string content;
	char ch;

	if (!file.is_open())
	{
		std::cerr << "Error opening file" << fileName <<std::endl;
		return "";
	}

	//reading from file and returning the content
	while (file.get(ch))
	{
		content += ch;
	}
	file.close();

	return content;
}

void FileHelper::writeWordsToFile(std::string inputFileName, std::string outputFileName)
{
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);
	std::string word;

	//errors checking
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening input file" << inputFileName << std::endl;
		return;
	}

	if (!outputFile.is_open()) 
	{
		std::cerr << "Error opening output file: " << outputFileName << std::endl;
		return;
	}

	//writing to the file from another file
	while (inputFile >> word)
	{
		outputFile << word << std::endl;
	}

	//closing files
	inputFile.close();
	outputFile.close();
}

void FileHelper::saveTextInFile(const std::string& text, const std::string& outputFileName)
{
	std::ofstream outputFile(outputFileName);
	if (!outputFile.is_open()) 
	{
		std::cerr << "Error opening output file: " << outputFileName << std::endl;
		return;
	}

	//writing to the file
	outputFile << text;

	//closing the file
	outputFile.close();
}
