#include "headers.h"

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        if (nums.size() <= 1 || k == 0) return false;
        int i = 1;
        s.insert(nums[0]);
        while (i < nums.size()) {
            long lower = static_cast<long>(nums[i]) - t,
                 upper = static_cast<long>(nums[i]) + t;
            auto pos1 = s.lower_bound(lower);
            if (pos1 != s.end() && *pos1 <= upper) return true;
            if (i - k >= 0 && s.find(nums[i - k]) != s.end())
                s.erase(nums[i - k]);
            s.insert(nums[i]);
            ++i;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    Solution t;
    cout << t.containsNearbyAlmostDuplicate(nums, 2, 3);
    return 0;
}