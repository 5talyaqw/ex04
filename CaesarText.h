#ifndef CAESARTEXT_H
#define CAESARTEXT_H

#include "ShiftText.h"
#include <string>

class CaesarText : public ShiftText 
{
public:
    CaesarText(const std::string& text);

    virtual ~CaesarText();

    static std::string encrypt(const std::string& text);


    static std::string decrypt(const std::string& text);

    std::string encrypt();

    std::string decrypt();
};

#endif // CAESARTEXT_H
