#pragma once

#include "PCEntry.h"
#include "PatternHistoryTable.h"
#include "LeastRecentlyUsed.h"

class BranchHistoryRegister {
public:
	BranchHistoryRegister(int patternSize, int tableSize);
	bool predict(unsigned int entry);
	void update(PCEntry entry);
private:
	int find(unsigned int address);
	int addEntry(unsigned int address);
	PatternHistoryTable** patterns;
	unsigned int* quickReference;
	int patternSize;
	int tableSize;
	LeastRecentlyUsed* lru;
	int taken;

};