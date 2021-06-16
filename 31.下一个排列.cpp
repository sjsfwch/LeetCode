/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=-1,j,k;
        for(j=nums.size()-1;j>0;j--){
            if(nums[j-1]<nums[j]) {i=j-1;break;}
        }
        if(i==-1) {sort(nums.begin(),nums.end());return;}
        for(int a=j,b=nums.size()-1;a<b;a++,b--) swap(nums[a],nums[b]);
        for(k=nums.size()-1;k>i;k--){
            if(nums[i]>=nums[k]) break;
        }
        swap(nums[i],nums[k+1]);
    }
};
// @lc code=end

int main(){
    Solution t;
    vector<int> x={1,1,2};
    t.nextPermutation(x);
    return 0;
}
