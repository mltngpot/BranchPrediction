#pragma once

#include <queue>
#include <unordered_map>

using namespace std;

class LeastRecentlyUsed {
    public:
      LeastRecentlyUsed();
      unsigned int getLeastUsed();
      void use(unsigned int entry);
    private:
      queue<unsigned int>* lruQueue;
      unordered_map<unsigned int, int>* lruUsage;
};