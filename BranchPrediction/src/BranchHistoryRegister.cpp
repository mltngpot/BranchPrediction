#include "include/BranchHistoryRegister.h"

using namespace std;

BranchHistoryRegister::BranchHistoryRegister(int patternSize, int tableSize)
{
    patterns = new PatternHistoryTable *[tableSize];
    lru = new LeastRecentlyUsed();
    taken = 0;
    this->patternSize = patternSize;
    this->tableSize = tableSize;
    this->quickReference = new unsigned int[tableSize];
}

bool BranchHistoryRegister::predict(unsigned int entry)
{
    int id = find(entry);
    if(id == -1){
        id = addEntry(entry);
    }
    lru->use(entry);
    return patterns[id]->predict();
}

void BranchHistoryRegister::update(PCEntry entry)
{
    int id = find(entry.address);
    if(id == -1) return;
    if(entry.taken){
        patterns[id]->didTake();
    } else {
        patterns[id]->didNotTake();
    }
}

int BranchHistoryRegister::find(unsigned int entry){
    for(int i = 0; i < taken; i++)
    {
        if(quickReference[i] == entry){
            return i;
        }
    }
    return -1;
}

int BranchHistoryRegister::addEntry(unsigned int entry){
    int id = -1;
    if(taken == tableSize){
        id = lru->getLeastUsed();
    } else {
        id = taken++;
    }
    quickReference[id] = entry;
    patterns[id] = new PatternHistoryTable(this->patternSize);

    return id;
}