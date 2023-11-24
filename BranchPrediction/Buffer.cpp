#include <iostream>
#include <queue>

#include "Buffer.h"
#include "BufferEntry.h"
#include "BranchPrediction.h"

using namespace std;

Buffer::Buffer(istream& input) {
	this->input = &input;
	this->buffer = new queue<BufferEntry>();
	this->reader = thread(&Buffer::readInput, this);
}

Buffer::~Buffer() {
	delete this->buffer;
	this->reader.join();
}

void Buffer::push(BufferEntry entry) {
	this->buffer->push_back(entry);
}

BufferEntry* Buffer::pop() {
	if (this->buffer->empty()) {
		return NULL;
	}
	BufferEntry entry = this->buffer->front();
	this->buffer->pop();
	return &entry;
}

bool Buffer::isEOF() {
	return this->thread.done() && this->buffer->empty();
}

void Buffer::readInput() {
	while(!this->input.eof()) {
		string line;
		getline(this->input, line);
		if (line.empty()) {
			continue;
		}
		string address = line.substr(0, 8);
		bool taken = line.substr(9, 1) == "+";
		this->buffer->push(BufferEntry(address, taken));
	}
}