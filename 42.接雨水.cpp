/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        int left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0,
            res = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(height[left], leftMax);
                res += leftMax - height[left];
                left++;
            } else {
                rightMax = max(height[right], rightMax);
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end
