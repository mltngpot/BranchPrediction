#pragma once

#include <iostream>
#include <string>
using namespace std;

class MainParameters {
public:
	MainParameters(int argc, char** argv);
	int getBHRSize();
	int getPHTSize();
	istream * getInputStream();
	string getStringParameter(string label);
	int getIntParameter(string label);

private:
	int argc;
	char** argv;

	const int PHT_HISTORY_SIZE = 4;
	const int BHR_SIZE = 512;
	const string TRACEFILE = "gccSmall.trace";
};