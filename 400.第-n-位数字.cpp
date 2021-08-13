/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int findNthDigit(int n) {
        int digit = 1, start = 1;
        long long count = 9;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9 * long(start) * digit;
        }
        int num = start + (n - 1) / digit;
        int pos = (n - 1) % digit;
        int res = 1;
        while (pos-- >= 0) {
            res = num / start;
            num %= start;
            start /= 10;
        }
        return res;
    }
};
// @lc code=end
int main() {
    Solution t;
    // auto x = typeid(t);
    t.findNthDigit(1000000000);
    return 0;
}