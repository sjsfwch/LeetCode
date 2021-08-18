#include "headers.h"

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int res=0,sum=0;
        unordered_map<int, int> tmp;
        tmp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0) ? -1 : 1;
            if(tmp.count(sum)!=0){
                res=max(res,i-tmp[sum]);
            }
            else tmp[sum]=i;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 0, 0, 0, 1, 1};
    Solution t;
    t.findMaxLength(nums);
    return 0;
}