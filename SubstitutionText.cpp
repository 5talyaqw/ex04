#include "SubstitutionText.h"
#include <iostream>
#include <fstream>

SubstitutionText::SubstitutionText(const std::string& text, const std::string& dictionaryFileName) : PlainText(text), _dictionaryFileName(dictionaryFileName)
{}

SubstitutionText::~SubstitutionText()
{}


std::string SubstitutionText::encrypt(const std::string& text, const std::string& dictionaryFileName)
{
	char sub[26] = { 0 };
	char plain;
	char cipher;
	std::string line;
	std::string encryptedText;
	std::ifstream file(dictionaryFileName);
	int i = 0;
	char ch;

	if (!file.is_open())
	{
		std::cerr << "couldnt open file" << std::endl;
		return "";
	}

	while (std::getline(file, line))
	{
		if (line.size() >= 3)
		{
			plain = line[0];
			cipher = line[2];
			sub[plain - 'a'] = cipher;
		}
	}
	file.close();

	encryptedText = text;
	for (i = 0;i < encryptedText.size(); i++)
	{
		ch = encryptedText[i];
		if (ch >= 'a' && ch <= 'z')
		{
			ch = sub[ch - 'a'];
			encryptedText[i] = ch;
		}
	}

	return encryptedText;
}

std::string SubstitutionText::decrypt(const std::string& text, const std::string& dictionaryFileName)
{
	char sub[26] = { 0 };
	char plain;
	char cipher;
	std::string line;
	std::string decryptedText;
	std::ifstream file(dictionaryFileName);
	int i = 0;
	char ch;


	if (!file.is_open())
	{
		std::cerr << "Couldn't open file: " << dictionaryFileName << std::endl;
		return "";
	}


	while (std::getline(file, line))
	{
		if (line.size() >= 3)
		{
			cipher = line[0];
			plain = line[2];
			sub[cipher - 'a'] = plain; 
		}
	}
	file.close();


	decryptedText = text;
	for (i = 0; i < decryptedText.size(); i++)
	{
		ch = decryptedText[i];
		if (ch >= 'a' && ch <= 'z')
		{
			decryptedText[i] = sub[ch - 'a'];
		}
	}

	return decryptedText;
}


std::string SubstitutionText::encrypt()
{
	if (isEn)
	{
		return text;
	}


	text = encrypt(text, _dictionaryFileName);
	isEn = true; 
	return text;
}

std::string SubstitutionText::decrypt()
{
	if (!isEn)
	{
		return text;
	}


	text = decrypt(text, _dictionaryFileName);
	isEn = false; 
	return text; 
}
