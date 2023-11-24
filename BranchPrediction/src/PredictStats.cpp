#include <iostream>
#include "include/PredictStats.h"

using namespace std;

PredictStats::PredictStats() {
	this->total = 0;
	this->correct = 0;
}

void PredictStats::update(bool prediction, bool actual) {
	this->total++;
	if (prediction == actual) {
		this->correct++;
	}
}

void PredictStats::print() {
	cout << "Total: " << this->total << endl;
	cout << "Correct: " << this->correct << endl;
	cout << "Incorrect: " << this->total - this->correct << endl;
	cout << "Accuracy: " << (double)this->correct / (double)this->total << endl;
}