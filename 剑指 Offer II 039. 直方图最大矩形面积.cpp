#include "headers.h"

class Solution {
   public:
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

int main() {
    Solution t;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    t.largestRectangleArea(heights);
    return 0;
}