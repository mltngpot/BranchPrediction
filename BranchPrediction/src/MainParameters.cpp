#include <fstream>

#include "include/MainParameters.h"

using namespace std;

MainParameters::MainParameters(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
}

int MainParameters::getPHTSize()
{
	int pht = getIntParameter("-pht");
	return pht == 0 ? PHT_HISTORY_SIZE : pht;
}

int MainParameters::getBHRSize()
{
	int bhr = getIntParameter("-bhr");
	return bhr == 0 ? BHR_SIZE : bhr;
}

istream* MainParameters::getInputStream()
{
	string tracefile = getStringParameter("-trace");
	if (tracefile == "")
	{
		tracefile = TRACEFILE;
	}

	istream* in = new ifstream(tracefile);
	return in;
}

int MainParameters::getIntParameter(string label)
{
	for (int i = 1; i < this->argc; i++)
	{
		if (strcmp(this->argv[i], label.c_str()) == 0 && i + 1 <= this->argc)
		{
			return atoi(this->argv[i + 1]);
		}
	}

	return 0;
}

string MainParameters::getStringParameter(string label)
{
	for (int i = 1; i < this->argc; i++)
	{
		if (strcmp(this->argv[i], label.c_str()) == 0 && i + 1 <= this->argc)
		{
			return string(this->argv[i + 1]);
		}
	}

	return string("");
}