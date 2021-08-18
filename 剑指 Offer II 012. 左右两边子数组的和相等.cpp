#include "headers.h"

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; ++i) pre[i + 1] = pre[i] + nums[i];
        int sum = *pre.rbegin() + *nums.rbegin();
        for (int i = 0; i < nums.size(); ++i) {
            int total = sum - nums[i];
            if (total % 2 != 0) continue;
            if (pre[i] == total / 2) return i;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, -7, -3, 6, 5, 6};
    // vector<int> nums = {-1, -1, -1, -1, 4, -1};
    Solution t;
    auto i = t.pivotIndex(nums);
    return 0;
}