#pragma once

#include <queue>
#include <iostream>
#include <thread>

#include "BufferEntry.h"

using namespace std;

class Buffer {
public:
	Buffer(istream& input);
	~Buffer();
	void push(BufferEntry entry);
	BufferEntry* pop();
	bool isEOF();
private:
	istream* input;
	thread reader;
	queue<BufferEntry>* buffer;
	void readInput();
};