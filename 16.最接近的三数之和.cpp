/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nearest=INT32_MAX,sum=0,dist=INT32_MAX,minDist=INT32_MAX;
        sort(nums.begin(),nums.end());
        for(int l=0;l<nums.size()-2;l++){
            int lo=l+1,hi=nums.size()-1;
            while(lo<hi){
                sum=nums[lo]+nums[l]+nums[hi];
                dist=abs(target-sum);
                if(dist<minDist){
                    if(dist==0) return target;
                    minDist=dist;
                    nearest=sum;
                }
                if(sum<target) lo++;
                else if(sum>target) hi--;
                else return target;
            }
        }
        return nearest;
    }
};
// @lc code=end

