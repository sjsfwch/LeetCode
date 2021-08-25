#include "headers.h"

class MovingAverage {
   private:
    vector<int> _data;
    int _cur;
    long long _sum;

   public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _data = vector<int>(size, 0);
        _cur = 0;
        _sum = 0;
    }

    double next(int val) {
        int cur = _cur % _data.size();
        _sum -= _data[cur];
        _sum += val;
        _data[cur] = val;
        _cur++;
        return 1.0 * _sum / min(_cur, int(_data.size()));
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */