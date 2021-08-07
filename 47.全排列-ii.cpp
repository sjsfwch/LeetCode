/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        do {
            res.push_back(nums);
        } while (next_permutation(begin(nums), end(nums)));
        return res;
    }
};
// @lc code=end
