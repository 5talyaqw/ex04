#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include "PlainText.h"
#include <string>

class SubstitutionText : public PlainText 
{
private:
    std::string _dictionaryFileName;

public:

    SubstitutionText(const std::string& text, const std::string& dictionaryFileName);


    virtual ~SubstitutionText();


    static std::string encrypt(const std::string& text, const std::string& dictionaryFileName);


    static std::string decrypt(const std::string& text, const std::string& dictionaryFileName);

    std::string encrypt();


    std::string decrypt();
};

#endif // SUBSTITUTIONTEXT_H
