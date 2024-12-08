#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <string>


class FileHelper
{
public:
	static std::string readFileToString(const std::string& fileName);
	static void writeWordsToFile(std::string inputFileName, std::string outputFileName);
	static void saveTextInFile(const std::string& text, const std::string& outputFileName);
};
#endif // !FILEHELPER_H

