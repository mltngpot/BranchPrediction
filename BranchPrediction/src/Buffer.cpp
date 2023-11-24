#include <iostream>
#include <queue>

#include "include/Buffer.h"
#include "include/BufferEntry.h"
#include "include/BranchPrediction.h"

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
	this->buffer->push(entry);
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
	return this->buffer->empty();
}

void Buffer::readInput() {
	string line;
	istream stream = (this->input);
	while(getline(stream, line)) {
		if (line.empty()) {
			continue;
		}
		string addressHex = line.substr(0, 8);
		unsigned int address = stoul(addressHex, NULL, 16);
		bool taken = line.substr(9, 1) == "+";
		this->buffer->push(BufferEntry(address, taken));
	}
}