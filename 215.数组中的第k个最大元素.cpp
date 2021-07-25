/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
        return nums[k - 1];
    }
};
// @lc code=end
