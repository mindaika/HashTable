#include "DialogElement.h"

DialogElement::DialogElement() : id(), elementText()
{
}

DialogElement::DialogElement(char* setID, const char* setTEXT) : id(), elementText()
{
	strcpy_s(id, MAX_ID_LENGTH, setID);
	strcpy_s(elementText, MAX_DIAG_LENGTH, setTEXT);
}

DialogElement::~DialogElement(void)
{
}

char* DialogElement::getID()
{
	return id;
}

char* DialogElement::getText()
{
	return elementText;
}

std::ostream& operator<<(std::ostream& os, const DialogElement& element)
{
	os << element.id << " " << element.elementText << std::endl;
	return os;
}