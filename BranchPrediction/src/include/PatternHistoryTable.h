#pragma once

class PatternHistoryTable {
public:
	PatternHistoryTable(int patternLength = 4);
	bool predict();
	void didTake();
	void didNotTake();
private:
	unsigned int current = 0;
	unsigned int* counters;
	unsigned int currentMask;
	void took(bool took);
	unsigned int getCurrentCounter();
	unsigned int getCounterMask(int shift);
	int getCounterShift();
	int extractTakeValue(unsigned int counter, unsigned int mask, int shift);
	void saveTakeValue(unsigned int counter, unsigned int mask, int shift, int takeValue);
};