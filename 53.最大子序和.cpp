/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = INT32_MIN, cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur = (cur <= 0 ? 0 : cur);
            cur += nums[i];
            maxsub = max(maxsub, cur);
        }
        return maxsub;
    }
};
// @lc code=end

int main() {}