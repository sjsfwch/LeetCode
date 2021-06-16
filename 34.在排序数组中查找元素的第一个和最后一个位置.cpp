/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>{-1,-1};
        int lo=0,hi=nums.size();
        int res1=-1,res2=-1;
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(target<=nums[m]) hi=m;
            else lo=m+1;
        }
        if(lo<nums.size()&&nums[lo]==target) res1=lo;
        lo=res1>0?res1:0,hi=nums.size();
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(target<nums[m]) hi=m;
            else lo=m+1;
        }
        if(hi>0&&nums[hi-1]==target) res2=hi-1;
        return vector<int>{res1,res2};
    }
};
// @lc code=end

int main(){
    Solution t;
    vector<int> x={2,2};
    auto y=t.searchRange(x,3);
    return 0;
}