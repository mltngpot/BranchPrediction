#include <fstream>

#include "include/BranchPrediction.h"
#include "include/Buffer.h"
#include "include/BufferEntry.h"
#include "include/PatternHistoryTable.h"
#include "include/PredictStats.h"

using namespace std;

static int PHT_HISTORY_SIZE = 4;

int main()
{
	ifstream input("gccSmall.trace");
	Buffer* buffer = new Buffer(input);

	PatternHistoryTable* pht = new PatternHistoryTable(PHT_HISTORY_SIZE);

	PredictStats stats = PredictStats();

	while (!buffer->isEOF())
	{
		BufferEntry entry = buffer->pop();
		bool prediction = pht->predict(entry.address);
		stats.update(prediction, entry.taken);
		pht->update(entry);
	};

	stats.print();

}
