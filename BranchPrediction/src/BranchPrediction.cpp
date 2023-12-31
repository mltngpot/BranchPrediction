﻿#include <fstream>

#include "include/BranchPrediction.h"
#include "include/PCBuffer.h"
#include "include/PCEntry.h"
#include "include/BranchHistoryRegister.h"
#include "include/PredictStats.h"
#include "include/MainParameters.h"

using namespace std;

int main(int argc, char* argv[])
{
	MainParameters params(argc, argv);
	int phtSize = params.getPHTSize();
	int bhrSize = params.getBHRSize();
	istream* in = params.getInputStream();
	ofstream out("output.trace", ofstream::out);

	PCBuffer* buffer = new PCBuffer(*in);

	BranchHistoryRegister* bhr = new BranchHistoryRegister(phtSize, bhrSize);

	PredictStats stats = PredictStats();
	string SPACE = " ";
	while (!buffer->isEOF())
	{
		PCEntry entry = buffer->pop();
		bool prediction = bhr->predict(entry.address);
		stats.update(prediction, entry.taken);
		bool accuracy = prediction == entry.taken;
		out << entry.address << SPACE << entry.taken << SPACE << prediction << SPACE << accuracy << endl;
		bhr->update(entry);
	};

	stats.print();

}