#include "PlainText.h"

int PlainText::numOfTexts = 0;

PlainText::PlainText(const std::string& text) : text(text), isEn(false)
{
	++numOfTexts;
}

PlainText::~PlainText(){}

bool PlainText::isEncrypted() const
{
	return isEn;
}

std::string PlainText::getText() const
{
	return text;
}
