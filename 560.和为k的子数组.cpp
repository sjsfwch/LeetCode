/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, pre = 0;
        unordered_map<int, int> tmp;
        tmp[0] = 1;
        for (auto& x : nums) {
            pre += x;
            if (tmp.find(pre - k) != tmp.end()) count += tmp[pre - k];
            tmp[pre]++;
        }
        return count;
    }
};
// @lc code=end
