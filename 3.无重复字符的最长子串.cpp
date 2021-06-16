/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "headers.h"
using namespace std;
// @lc code=start
#define max(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag(128,-1);
        int maxLen=0,start=0;
        for(int i=0;i<s.size();i++){
            // 命中
            if (flag[s[i]]>=0){
                maxLen=max(maxLen,i-start);
                if (flag[s[i]]>=start)
                {start=start+1;
                if (start<=flag[s[i]]) start=flag[s[i]]+1;
                }
            }
            flag[s[i]]=i;
        }
        maxLen=max(s.size()-start,maxLen);
        return maxLen;
    }
};
// @lc code=end

int main(){
    Solution t;
    string input="ohvhjdml";
   t.lengthOfLongestSubstring(input);
   return 0;

}
