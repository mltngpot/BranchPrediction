#pragma once

class PredictStats {
public:
	PredictStats();
	void update(bool prediction, bool actual);
	void print();
private:
	int total;
	int correct;
};