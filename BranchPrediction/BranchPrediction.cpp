#include "BranchPrediction.h"
#include "Buffer.h"
#include "BufferEntry.h"
#include "PatternHistoryTable.h"

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
