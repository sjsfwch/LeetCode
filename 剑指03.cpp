#include "headers.h"
using namespace std;

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    res = nums[i];
                    break;
                } else {
                    int temp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[temp] = temp;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums={2, 3, 1, 0, 2, 5, 3};
    Solution t;
    int res=t.findRepeatNumber(nums);
    return 0;
}