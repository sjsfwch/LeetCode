#include "headers.h"
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0, hi = 0, sum = 0, minLen = nums.size() + 1;
        while (hi < nums.size()) {
            sum += nums[hi];
            hi++;
            while (sum >= target && lo < hi) {
                minLen = min(minLen, hi - lo);
                sum -= nums[lo];
                lo++;
            }
        }
        return (minLen == nums.size() + 1) ? 0 : minLen;
    }
};

class Solution1 {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // pre[i]=sum(nums[:i]) [0,i)
        int n = nums.size();
        auto pre = getPre(nums);
        int minLen = nums.size() + 1;
        if (*pre.rbegin() < target) return 0;
        if (*pre.rbegin() == target) return nums.size();
        for (int i = 0; i < pre.size() - 1; i++) {
            int remain = target + pre[i];
            if (remain > *pre.rbegin()) break;
            int pos =
                lower_bound(pre.begin() + i, pre.end(), remain) - pre.begin();
            minLen = min(minLen, pos - i);
        }
        return minLen;
    }
    vector<int> getPre(vector<int>& nums) {
        vector<int> pre(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) pre[i + 1] = pre[i] + nums[i];
        return pre;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution t;
    t.minSubArrayLen(7, nums);
    return 0;
}