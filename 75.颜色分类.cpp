/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0,p2=nums.size()-1;
        for (int i = 0;i<=p2;i++){
            while (nums[i]==2&&i<=p2){
                swap(nums[i],nums[p2]);
                p2--;
            }
            if(nums[i]==0){
                swap(nums[i],nums[p0]);
                p0++;
            }
        }
    }
};
// @lc code=end

int main(){
    vector<int> nums={2,1,2};
    Solution t;
    t.sortColors(nums);
    return 0;
}
