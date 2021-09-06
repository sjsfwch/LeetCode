/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (nums[mi] == target)
                return mi;
            else if (nums[mi] < target)
                lo = mi + 1;
            else
                hi = mi;
        }
        return -1;
    }
};
// @lc code=end
int main() {
    Solution t;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    t.search(nums, -2);
    return 0;
}