#include "headers.h"

class Solution {
   public:
    int maximalRectangle(vector<string>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> heights;
            for (int j = 0; j < matrix[0].size(); ++j) {
                int k = i;
                while (k < matrix.size() && matrix[k][j] == '1') ++k;
                heights.push_back(k - i);
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), 0), right(heights.size(), 0);
        calLeftRight(heights, left, right);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }

    void calLeftRight(vector<int>& heights, vector<int>& left,
                      vector<int>& right) {
        stack<int> tmp;
        // cal left
        // 哨兵
        tmp.push(-1);
        for (int i = 0; i < heights.size(); ++i) {
            while (tmp.top() != -1 && heights[tmp.top()] >= heights[i])
                tmp.pop();
            left[i] = tmp.top();
            tmp.push(i);
        }
        while (!tmp.empty()) tmp.pop();
        // cal right
        // 哨兵
        tmp.push(heights.size());
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (tmp.top() != heights.size() &&
                   heights[tmp.top()] >= heights[i])
                tmp.pop();
            right[i] = tmp.top();
            tmp.push(i);
        }
    }
};