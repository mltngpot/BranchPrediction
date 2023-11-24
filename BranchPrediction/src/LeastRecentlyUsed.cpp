#include "include/LeastRecentlyUsed.h"

LeastRecentlyUsed::LeastRecentlyUsed()
{
	this->lruQueue = new queue<unsigned int>();
	this->lruUsage = new unordered_map<unsigned int, int>();
}

unsigned int LeastRecentlyUsed::getLeastUsed()
{
	unsigned int leastUsed;
	int leastUsedCount;
	do {
		unsigned int leastUsed = this->lruQueue->front();
		this->lruQueue->pop();
		leastUsedCount = this->lruUsage->at(leastUsed);
		leastUsedCount--;
		this->lruUsage->at(leastUsed) = leastUsedCount;
	} while (leastUsedCount > 0);
	return leastUsed;
}

void LeastRecentlyUsed::use(unsigned int entry)
{
	this->lruQueue->push(entry);
	if (this->lruUsage->find(entry) == this->lruUsage->end())
	{
		this->lruUsage->insert({entry, 1});
	}
	else
	{
		int value = this->lruUsage->at(entry);
		value++;
		this->lruUsage->at(entry) = value;
	}	
}
