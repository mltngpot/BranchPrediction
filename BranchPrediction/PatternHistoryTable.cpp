#include "PatternHistoryTable.h"

using namespace std;

PatternHistoryTable::PatternHistoryTable(int size)
{
    patterns = new PatternCounter*[size];
    lru = new LeastRecentlyUsed();
    taken = 0;
    this->size = size;
}

bool PatternHistoryTable::predict(unsigned int entry)
{
    int id = find(entry);
    if(id == -1){
        id = addEntry(entry);
    }
    lru->use(entry);
    return patterns[id]->predict();
}

void PatternHistoryTable::update(BufferEntry entry) 
{
    int id = find(entry.address);
    if(id == -1) return;
    if(entry.taken){
        patterns[id]->didTake();
    } else {
        patterns[id]->didNotTake();
    }
}

int PatternHistoryTable::find(unsigned int entry){
    for(int i = 0; i < taken; i++)
    {
        if(quickReference[i] == entry){
            return i;
        }
    }
    return -1;
}

int PatternHistoryTable::addEntry(unsigned int entry){
    int id = -1;
    if(taken == size){
        id = lru->getLeastUsed();
    } else {
        id = taken++;
    }
    quickReference[id] = entry;
    patterns[id] = new PatternCounter();

    return id;
}