#include "headers.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> tmp(128, 0);
        auto check = [&tmp]() {
            for (auto &n : tmp) {
                if (n > 1) return false;
            }
            return true;
        };
        int lo = 0, hi = 0, res = 0;
        bool flag = true;
        while (hi < s.size()) {
            auto idx = flag ? s[hi++] - 'a' : s[lo++] - 'a';
            if (flag) {
                tmp[idx]++;
                if (tmp[idx] > 1) {
                    flag = false;
                    continue;
                }
                res = max(res, hi - lo);
            } else {
                tmp[idx]--;
                if (tmp[idx] == 1) {
                    flag = true;
                }
            }
        }
        return res;
    }
};