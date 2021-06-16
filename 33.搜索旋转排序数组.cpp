/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,m=-1,hi=nums.size();
        while(lo<hi){
            m=(lo+hi)>>1;
            if(nums[m]==target) return m;
            // lo,hi为递增
            if(nums[lo]<=nums[hi-1]){
                if(nums[m]<target) lo=m+1;
                else hi=m;
            }
            // lo,m为递增
            else if(nums[lo]<=nums[m]){
                if(target<nums[m]&&target>=nums[lo]) hi=m;
                else lo=m+1;
            }
            // m,hi为递增
            else{
                if(target>nums[m]&&target<=nums[hi-1]) lo=m+1;
                else hi=m;
            }

        }
        if (m>-1&&nums[m]==target) return m;
        return -1;
    }
};
// @lc code=end

int main(){
    Solution t;
    vector<int> x;
    auto y=t.search(x,3);
    return 0;
}