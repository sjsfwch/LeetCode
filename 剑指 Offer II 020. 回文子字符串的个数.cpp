#include "headers.h"

class Solution {
   public:
    int countSubstrings(string s) {
        int res = 0, lo, hi;
        for (int i = 0; i < s.size(); ++i) {
            res++;
            // 以当前点为中心
            lo = i - 1, hi = i + 1;
            while (lo >= 0 && hi < s.size()) {
                if (s[lo--] != s[hi++]) break;
                res++;
            }
            // 以当前点和下一个点为中心
            lo = i, hi = i + 1;
            while (lo >= 0 && hi < s.size()) {
                if (s[lo--] != s[hi++]) break;
                res++;
            }
        }
        return res;
    }
};