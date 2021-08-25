#include "headers.h"

class RecentCounter {
    queue<int> _times;

   public:
    RecentCounter() {}

    int ping(int t) {
        _times.push(t);
        int start = t - 3000;
        while (_times.front() < start) _times.pop();
        return _times.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */