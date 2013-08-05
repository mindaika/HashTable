#include "hashtable.h"

HashTable::HashTable(void) : table()
{
	entryCount = 0;
}


HashTable::~HashTable(void)
{
}

bool HashTable::put(DialogElement& element)
{
	bool success = false;
	int hashIndex = Hasher(element.getID());
	// Insert item in first empty List slot at table index
	if ( table[ hashIndex ].insert(table[ hashIndex ].getLength() + 1, element ) ) {
		success = true;
		entryCount++;
	}
	return success;
}
	
bool HashTable::remove(char* element)
{
	bool success = false;
	// Compute HashIndex
	int hashIndex = Hasher( element );
	// Check to see if there is a match in HashTable
	// Check to see if any items are in indexed location
	if ( table[ hashIndex ].isEmpty() ) {
		// Think about why you wrote a space for this
	} else {
		// Cycle through list indices
		for ( int j = 1; j < table[hashIndex].getLength() + 1; j++ ) {
			// Remove item
			if ( !(strcmp( table[hashIndex].getEntry(j).getID(), element) ) ) {
				table[hashIndex].remove(j);
				success = true;
			}
		}
	}

	return success;
}

void HashTable::dumpTable(std::ostream& outList, bool flag)
{
	std::cout << "====================" << std::endl;
	std::cout << "Hash Table Diagnostics" << std::endl << std::endl;
	std::cout << "Table Size: " << TABLE_SIZE << std::endl;
	std::cout << "Number of Entries: " << entryCount << std::endl;

	if (!flag) {
		// Cycle through table indices
		for ( int i = 0; i < TABLE_SIZE - 1;  i++ ) {
			// Check whether indice is empty
			if ( !(table[i].isEmpty() ) ) {
				std::cout << "Slot[" << i << "]:" << std::endl;
				// Cycle through list indices
				for ( int j = 1; j < table[i].getLength() + 1; j++ ) {
					std::cout << "  " << table[i].getEntry(j) << std::endl;
				} 
			}
		}
	} else {
		for ( int i = 0; i < TABLE_SIZE - 1;  i++ ) {
			std::cout << "Slot[" << i << "]:" << std::endl;
			std::cout << "  " << table[i].getEntry(0) << std::endl;
		}		
	}
	std::cout << "====================" << std::endl;
}
	
DialogElement* HashTable::get(char* element)
{
	DialogElement* returnElement = nullptr;
	int hashIndex = Hasher( element );
	// Check to see if any items are in indexed location
	if ( table[ hashIndex ].isEmpty() ) {
		// Think about why you wrote a space for this
	} else {
		// Cycle through list indices
		for ( int j = 1; j < table[hashIndex].getLength() + 1; j++ ) {
			// Sigh... 0=False=Match; who wrote this? The Swiss?
			if ( !(strcmp( table[hashIndex].getEntry(j).getID(), element) ) ) {
				returnElement = &table[hashIndex].getEntry(j);
			}
		}
	}
	return returnElement; //&table[ Hasher( element ) ].getEntry(0);
}

int HashTable::Hasher(char* element)
{
	int h = 0;
    int len = strlen( element );
    for (int i = 0; i < len; i++) {
		h = ( 31 * h + element[i] ) % TABLE_SIZE;
    }
    return h;
}