#include "headers.h"

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> asist;
        asist[0] = 1;
        int sum = 0, res = 0;
        for (auto& num : nums) {
            sum += num;
            res += asist.count(sum - k) == 0 ? 0 : asist[sum - k];
            asist[sum]++;
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<int> nums = {1, 0, 1, 1};
    t.subarraySum(nums, 2);
    return 0;
}