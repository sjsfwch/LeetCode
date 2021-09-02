#include "headers.h"

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        bool start = false;
        int count0 = 0, count1 = 0, base = 0;
        for (auto &c : s) {
            if ((!start) && c == '1') start = true;
            if (start) {
                if (c == '1')
                    count1++;
                else
                    count0++;
                if (count0 == count1) {
                    start = false;
                    base += count0;
                    count0 = 0;
                    count1 = 0;
                }
            }
        }
        return min(count0, count1) + base;
    }
};