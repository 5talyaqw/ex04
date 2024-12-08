#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <string>


class PlainText
{
protected:
	std::string text;
	bool isEn;

public:
	static int numOfTexts;

	PlainText(const std::string& text);
	virtual ~PlainText();

	bool isEncrypted() const;

	std::string getText() const;
};
#endif // PLAINTEXT_H

