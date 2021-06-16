/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for (auto c:t){
            if(need.find(c)!=need.end()) need[c]=1;
            else need[c]++;
        }
        int i=0,j=0,minj=-1,mini=-1;
        bool flag=false;
        while(j<s.size()){
            // 没彻底包含t
            if(flag){
                if(need.find(s[j])!=need.end()) need[s[j]]--;
                j++;
            }
            else{
                if(need.find(s[i])!=need.end()) need[s[i]]++;
                i++;
            }
        }
    }
};
// @lc code=end

