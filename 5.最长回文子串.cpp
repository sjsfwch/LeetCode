/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<2) return s;
        int c,lo,hi,maxLen=1;
        string res=s.substr(0,1);
        for(c=0;c<s.size()-1;c++){
            lo=hi=c;
            while(lo>=0&&hi<s.size()){
                if (s[lo]==s[hi]){
                    if ((hi-lo+1)>maxLen){
                        maxLen=hi-lo+1;
                        res=s.substr(lo,maxLen);
                    }
                }
                else break;
                lo--;
                hi++;
            }
            lo=c,hi=c+1;
            while(lo>=0&&hi<s.size()){
                if (s[lo]==s[hi]){
                    if ((hi-lo+1)>maxLen){
                        maxLen=hi-lo+1;
                        res=s.substr(lo,maxLen);
                    }
                }
                else break;
                lo--;
                hi++;
            }
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution t;
    auto res=t.longestPalindrome("abba");
    return 0;
}

