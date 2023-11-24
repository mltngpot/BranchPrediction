#pragma once

#include <queue>

using namespace std;

class LeastRecentlyUsed {
    public:
      LeastRecentlyUsed();
      unsigned int getLeastUsed();
      void use(unsigned int entry);
    private:
      queue<int> lruQueue;
};