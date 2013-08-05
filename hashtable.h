#ifndef _HASH_TABLE
#define _HASH_TABLE
#include "DialogElement.h"
#include "LinkedList.h"
//#include "HashedEntry.h"



class HashTable
{
	static const int TABLE_SIZE = 100;
	int entryCount;
public:
	HashTable(void);
	~HashTable(void);
	bool put(DialogElement&);
	bool remove(char*);
	void dumpTable(std::ostream&, bool);	
	DialogElement* get(char*);
private:
	LinkedList<DialogElement> table[TABLE_SIZE];
	int Hasher(char*);
};
#endif
