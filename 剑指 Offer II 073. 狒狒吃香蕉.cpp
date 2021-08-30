#include "headers.h"

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto eat = [&piles](const int speed) {
            int res = 0;
            for (auto i : piles) {
                res += i / speed;

                if (i % speed != 0) res++;
            }
            return res;
        };
        sort(piles.begin(), piles.end());
        int lo = 1, hi = piles.back();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            auto eh = eat(mi);
            if (eh <= h)
                hi = mi;
            else
                lo = mi + 1;
        }
        return lo;
    }
};