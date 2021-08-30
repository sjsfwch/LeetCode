#include "headers.h"

class Solution {
   public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mi = (lo + hi + 1) >> 1;
            long long r = (long long)(mi)*mi;
            if (r <= x)
                lo = mi;
            else
                hi = mi - 1;
        }
        return lo;
    }
};