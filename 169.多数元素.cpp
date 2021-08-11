/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == res)
                count++;
            else {
                count--;
                if (count == 0) {
                    count = 1;
                    res = nums[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
