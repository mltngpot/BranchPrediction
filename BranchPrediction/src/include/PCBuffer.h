#pragma once

#include <queue>
#include <iostream>
#include <thread>

#include "PCEntry.h"

using namespace std;

class PCBuffer {
public:
	PCBuffer(istream& input);
	~PCBuffer();
	void push(PCEntry entry);
	PCEntry pop();
	bool isEOF();
private:
	istream* input;
	thread reader;
	queue<PCEntry>* buffer;
	void readInput();
};