/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, cur = -100000, cur_count = 0;
        while (j < nums.size()) {
            if (nums[j] != cur) {
                cur = nums[j];
                cur_count = 1;
            } else {
                cur_count++;
            }
            if (cur_count <= 2) nums[i++] = nums[j];
            j++;
        }
        return i;
    }
};
// @lc code=end

int main() {
    Solution t;
    vector<int> nums = {1, 1, 1};
    cout << t.removeDuplicates(nums);
    return 0;
}