#pragma once

struct PCEntry {
	unsigned int address;
	bool taken;
	PCEntry(unsigned int address, bool taken) {
		this->address = address;
		this->taken = taken;
	}
};