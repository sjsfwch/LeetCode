#include "headers.h"
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            while (i - 1 >= 0 && i < nums.size() - 2 && nums[i] == nums[i - 1])
                i++;
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                if (nums[i] + nums[lo] + nums[hi] > 0)
                    hi--;
                else if (nums[i] + nums[lo] + nums[hi] < 0)
                    lo++;
                else {
                    res.push_back(vector<int>({nums[i], nums[lo], nums[hi]}));
                    lo++;
                    hi--;
                    while (lo < hi && nums[lo - 1] == nums[lo]) lo++;
                    while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<int> nums = {0, 0, 0, 0};
    t.threeSum(nums);
    return 0;
}