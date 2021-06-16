/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> tmp;
        for(int i=0;i<nums.size();i++){
            if (tmp.find(target-nums[i])!=tmp.end())
                {res.push_back(tmp[target-nums[i]]);
                res.push_back(i);
                break;}
            else
            {
                tmp[nums[i]]=i;
            }
            
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution t;
    int myints[] = {2,7,11,15};
   vector<int> input (myints, myints + sizeof(myints) / sizeof(int) );
   t.twoSum(input,9);
   return 0;

}