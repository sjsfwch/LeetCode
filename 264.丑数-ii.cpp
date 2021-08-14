/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n + 1, 1);
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i < ugly.size(); ++i) {
            ugly[i] = min(min(ugly[p2] * 2, ugly[p3] * 3), ugly[p5] * 5);
            if (ugly[i] == ugly[p2] * 2) p2++;
            if (ugly[i] == ugly[p3] * 3) p3++;
            if (ugly[i] == ugly[p5] * 5) p5++;
        }
        return ugly[n];
    }
};
// @lc code=end
