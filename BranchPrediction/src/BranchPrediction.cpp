#include "include/BranchPrediction.h"
#include "include/Buffer.h"
#include "include/BufferEntry.h"
#include "include/PatternHistoryTable.h"

using namespace std;

static int PHT_HISTORY_SIZE = 4;

int main()
{
	Buffer* buffer = new Buffer(cin);
	PatternHistoryTable* pht = new PatternHistoryTable(PHT_HISTORY_SIZE);
	
	while (!buffer->isEOF())
	{
		BufferEntry* entry = buffer->pop();
		pht->update(*entry);
	};

}
