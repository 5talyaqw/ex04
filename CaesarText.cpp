#include "CaesarText.h"
#include <iostream>

CaesarText::CaesarText(const std::string& text) : ShiftText(text, 3)
{}

CaesarText::~CaesarText()
{}

std::string CaesarText::encrypt(const std::string& text)
{
	return ShiftText::encrypt(text, 3);
}

std::string CaesarText::decrypt(const std::string& text)
{
	return ShiftText::decrypt(text, 3);
}

std::string CaesarText::encrypt()
{
    if (isEn)
    {
        return text;
    }

    text = ShiftText::encrypt(text, 3);
    isEn = true;
    return text;
}

std::string CaesarText::decrypt()
{
    if (!isEn)
    {
        return text;
    }

    text = ShiftText::decrypt(text, 3);
    isEn = false;
    return text;
}

