#include "ShiftText.h"
#include <iostream>

ShiftText::ShiftText(const std::string& text, int key) : PlainText(text), _key(key) {}


ShiftText::~ShiftText() {}


std::string ShiftText::encrypt(const std::string& text, int key)
{
    char ch;
    std::string res = text;

    for (int i = 0; i < res.size(); i++)
    {
        ch = res[i];
      
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + key) % 26 + 'a';
            res[i] = ch;
        }
    }
    std::cout << "encrypted" << std::endl;
    return res;
}


std::string ShiftText::decrypt(const std::string& text, int key)
{
    char ch;
    std::string res = text;

    for (int i = 0; i < res.size(); i++)
    {
        ch = res[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
            res[i] = ch;
        }
    }
    return res;
}


std::string ShiftText::encrypt() 
{
    if (isEn)
    {
        return text;
    }
    text = ShiftText::encrypt(text, _key);
    isEn = true;
    return text;
}

std::string ShiftText::decrypt()
{
    if (!isEn)
    {
        return text;
    }
    text = ShiftText::decrypt(text, _key);
    isEn = false;
    return text;
}
