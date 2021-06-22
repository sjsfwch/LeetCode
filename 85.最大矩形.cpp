/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include "headers.h"

// @lc code=start
class Solution {
   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        // 从上到下计算柱状图
        for (int i = 0; i < n; i++) {
            int start = 0, sum = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == '1') {
                    sum++;
                    tmp[j][i] = sum;
                } else {
                    sum = 0;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            res = max(res, largestRectangleArea(tmp[i]));
        }
        return res;
    }

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
    Solution t;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '1'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    t.maximalRectangle(matrix);
    return 0;
}