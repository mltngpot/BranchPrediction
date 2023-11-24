#include "include/PatternCounter.h"

PatternCounter::PatternCounter(int patternLength){
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

bool PatternCounter::predict(){
    unsigned int counter = getCurrentCounter();
    int shift = getCounterShift();
    unsigned int mask = getCounterMask(shift);
    int takeValue = extractTakeValue(counter, shift, mask);

    return takeValue > 1;
}

void PatternCounter::didTake(){
    took(true);
}

void PatternCounter::didNotTake(){
    took(false);
}

void PatternCounter::took(bool took){
    unsigned int counter = getCurrentCounter();
    int shift = getCounterShift();
    unsigned int mask = getCounterMask(shift);
    int takeValue = extractTakeValue(counter, shift, mask);

    took ? takeValue++ : takeValue--;

    saveTakeValue(counter, shift, mask, takeValue);

    current = current << 1;
    if(took){
        current++;
    }

    current = current & currentMask;
}

unsigned int PatternCounter::getCurrentCounter(){
    int index = current / 16;
    int counter = this->counters[index];
    return counter;
}

unsigned int PatternCounter::getCounterMask(int shift){
    unsigned int mask = 3;
    mask = mask << shift;
    return mask;
}

int PatternCounter::getCounterShift(){
    int lastFour = current % 16;
    int shift = lastFour * 2;
    return shift;
}

int PatternCounter::extractTakeValue(unsigned int counter, unsigned int mask, int shift){
    int takeValue = counter & mask;
    takeValue = takeValue >> shift;
    return takeValue;
}

void PatternCounter::saveTakeValue(unsigned int counter, unsigned int mask, int shift, int takeValue){
     if(takeValue > 3){
        takeValue = 3;
    } else if(takeValue < 0){
        takeValue = 0;
    }

    unsigned int unchangedPart = counter & ~mask;
    unsigned int changedPart = takeValue << shift;
    counter = unchangedPart & changedPart;
    
    int index = current / 16;
    this->counters[index] = counter;
}