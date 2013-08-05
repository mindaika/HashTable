#ifndef _DIALOG_ELEMENT
#define _DIALOG_ELEMENT
#include <iostream>

class DialogElement
{
	static const int MAX_ID_LENGTH = 16;
	static const int MAX_DIAG_LENGTH = 2048;
public:
	DialogElement();
	DialogElement(char*, const char*);
	~DialogElement(void);
	char* getID();
	char* getText();
	friend std::ostream& operator<<(std::ostream&, const DialogElement&);

private:
	char id[MAX_ID_LENGTH];
	char elementText[MAX_DIAG_LENGTH];
};
#endif