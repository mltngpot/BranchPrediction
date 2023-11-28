#include <iostream>
#include <queue>

#include "include/PCBuffer.h"
#include "include/PCEntry.h"

using namespace std;

PCBuffer::PCBuffer(istream& inStream) {
	this->input = &inStream;
	this->buffer = new queue<PCEntry>();
	//this->reader = thread(&Buffer::readInput, this);
	this->readInput();
}

PCBuffer::~PCBuffer() {
	delete this->buffer;
}

void PCBuffer::push(PCEntry entry) {
	this->buffer->push(entry);
}

PCEntry PCBuffer::pop() {
	PCEntry entry = this->buffer->front();
	this->buffer->pop();
	return entry;
}

bool PCBuffer::isEOF() {
	return this->buffer->empty();
}

void PCBuffer::readInput() {
	string line;
	while(getline(*this->input, line)) {
		if (line.empty()) {
			continue;
		}
		string addressHex = line.substr(0, 8);
		unsigned int address = stoul(addressHex, NULL, 16);
		bool taken = line.substr(9, 1) == "+";
		this->buffer->push(PCEntry(address, taken));
	}
}