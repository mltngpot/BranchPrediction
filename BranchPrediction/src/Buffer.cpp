#include <iostream>
#include <queue>

#include "include/Buffer.h"
#include "include/BufferEntry.h"
#include "include/BranchPrediction.h"

using namespace std;

Buffer::Buffer(istream& inStream) {
	this->input = &inStream;
	this->buffer = new queue<BufferEntry>();
	//this->reader = thread(&Buffer::readInput, this);
	this->readInput();
}

Buffer::~Buffer() {
	delete this->buffer;
}

void Buffer::push(BufferEntry entry) {
	this->buffer->push(entry);
}

BufferEntry Buffer::pop() {
	BufferEntry entry = this->buffer->front();
	this->buffer->pop();
	return entry;
}

bool Buffer::isEOF() {
	return this->buffer->empty();
}

void Buffer::readInput() {
	string line;
	while(getline(*this->input, line)) {
		if (line.empty()) {
			continue;
		}
		string addressHex = line.substr(0, 8);
		unsigned int address = stoul(addressHex, NULL, 16);
		bool taken = line.substr(9, 1) == "+";
		this->buffer->push(BufferEntry(address, taken));
	}
}