#include <fstream>

#include "include/BranchPrediction.h"
#include "include/Buffer.h"
#include "include/BufferEntry.h"
#include "include/PatternHistoryTable.h"
#include "include/PredictStats.h"

using namespace std;

static int PHT_HISTORY_SIZE = 4;
static int PHT_TABLE_SIZE = 4096;

int main()
{
	ifstream in("gccSmall.trace");
	Buffer* buffer = new Buffer(in);

	PatternHistoryTable* pht = new PatternHistoryTable(PHT_HISTORY_SIZE, PHT_TABLE_SIZE);

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
