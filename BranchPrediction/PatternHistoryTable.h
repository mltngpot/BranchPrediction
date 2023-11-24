#include "BufferEntry.h"
#include "PatternCounter.h"
#include "LeastRecentlyUsed.h"

class PatternHistoryTable {
	public:
	PatternHistoryTable(int size);
	bool predict(unsigned int entry);
	void update(BufferEntry entry);
	private:
	int find(unsigned int address);
	int addEntry(unsigned int address);
	PatternCounter** patterns;
	int* quickReference;
	int size;
	LeastRecentlyUsed* lru;
	int taken;

};