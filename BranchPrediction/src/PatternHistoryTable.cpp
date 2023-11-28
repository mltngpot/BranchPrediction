#include "include/PatternHistoryTable.h"

PatternHistoryTable::PatternHistoryTable(int patternLength){
    int arraySize = patternLength - 3;
    if(arraySize < 1){
        arraySize = 1;
    }

    this->counters = new unsigned int [arraySize];
    for(int i = 0; i < arraySize; i++){
        this->counters[i] = 0;
    }

    currentMask = 0;
    for(int i = 1; i < patternLength; i++)
    {
        currentMask = ++currentMask << 1;
    }
}

bool PatternHistoryTable::predict(){
    unsigned int counter = getCurrentCounter();
    int shift = getCounterShift();
    unsigned int mask = getCounterMask(shift);
    int takeValue = extractTakeValue(counter, mask, shift);

    return takeValue > 1;
}

void PatternHistoryTable::didTake(){
    took(true);
}

void PatternHistoryTable::didNotTake(){
    took(false);
}

void PatternHistoryTable::took(bool took){
    unsigned int counter = getCurrentCounter();
    int shift = getCounterShift();
    unsigned int mask = getCounterMask(shift);
    int takeValue = extractTakeValue(counter, mask, shift);

    took ? takeValue++ : takeValue--;
    saveTakeValue(counter, mask, shift, takeValue);

    current = current << 1;
    if(took){
        current++;
    }

    current = current & currentMask;
}

unsigned int PatternHistoryTable::getCurrentCounter(){
    int index = current / 16;
    int counter = this->counters[index];
    return counter;
}

unsigned int PatternHistoryTable::getCounterMask(int shift){
    unsigned int mask = 3;
    mask = mask << shift;
    return mask;
}

int PatternHistoryTable::getCounterShift(){
    int lastFour = current % 16;
    int shift = lastFour * 2;
    return shift;
}

int PatternHistoryTable::extractTakeValue(unsigned int counter, unsigned int mask, int shift){
    int takeValue = counter & mask;
    takeValue = takeValue >> shift;
    return takeValue;
}

void PatternHistoryTable::saveTakeValue(unsigned int counter, unsigned int mask, int shift, int takeValue){
     if(takeValue > 3){
        takeValue = 3;
    } else if(takeValue < 0){
        takeValue = 0;
    }
    unsigned int invertedMask = ~mask;
    unsigned int unchangedPart = counter & invertedMask;
    unsigned int changedPart = takeValue << shift;
    counter = unchangedPart | changedPart;
    
    int index = current / 16;
    this->counters[index] = counter;
}