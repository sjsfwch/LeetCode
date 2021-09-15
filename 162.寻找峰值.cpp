/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        auto get = [&nums](const int i) -> pair<int, int> {
            if (i < 0 || i >= nums.size())
                return {0, 0};
            else
                return {1, nums[i]};
        };
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mi = (lo + hi) >> 1;
            if (get(mi) > get(mi + 1) && get(mi) > get(mi - 1))
                return mi;
            else if (get(mi) < get(mi + 1))
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        return lo;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {3, 1, 2};
    Solution t;
    t.findPeakElement(nums);
    return 0;
}