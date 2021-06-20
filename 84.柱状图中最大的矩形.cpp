/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        if (heights.empty()) return 0;
        int lo = 0, hi = 0, res = 0, h = heights[0];
        int dp[m] = {0};
        while (hi < m) {
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> h = {2, 1, 5, 6, 2, 3};
    Solution t;
    t.largestRectangleArea(h);
    return 0;
}