/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    double myPow(double x, int n) {
                if (n < 0) {
            if (n == INT32_MIN)
                return 1 / myPow(x, INT32_MAX) / x;
            else
                return 1 / myPow(x, -n);
        }
        if (n == 0) return 1.0;
        // double m = x;
        double res = 1;
        while (n > 0) {
            if (n & 0x1) res *= x;
            n >>= 1;
            x *= x;
        }
        return res;
    }
};
// @lc code=end
int main() {
    Solution t;
    t.myPow(1.0, INT32_MIN);
    return 0;
}