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
        int n = heights.size();
        vector<int> left(n, 0), right(n, n);
        stack<int> tmp;
        // cal left
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && heights[tmp.top()] >= heights[i]) {
                tmp.pop();
            }
            left[i] = tmp.empty() ? -1 : tmp.top();
            tmp.push(i);
        }
        while (!tmp.empty()) tmp.pop();
        // cal right
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && heights[tmp.top()] >= heights[i]) {
                tmp.pop();
            }
            right[i] = tmp.empty() ? n : tmp.top();
            tmp.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
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