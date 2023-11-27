#pragma once

#include "BufferEntry.h"
#include "PatternCounter.h"
#include "LeastRecentlyUsed.h"

class PatternHistoryTable {
	public:
	PatternHistoryTable(int patternSize, int tableSize);
	bool predict(unsigned int entry);
	void update(BufferEntry entry);
	private:
	int find(unsigned int address);
	int addEntry(unsigned int address);
	PatternCounter** patterns;
	unsigned int* quickReference;
	int patternSize;
	int tableSize;
	LeastRecentlyUsed* lru;
	int taken;

};