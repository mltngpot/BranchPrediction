#pragma once

struct BufferEntry {
	unsigned int address;
	bool taken;
	BufferEntry(unsigned int address, bool taken){
		this->address = address;
		this->taken = taken;
	}
};