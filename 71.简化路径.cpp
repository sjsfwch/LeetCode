/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "headers.h"

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmp,words=split(path);
        for(int i=0;i<words.size();i++){
            if(words[i]==".") continue;
            else if (words[i]==".."){
                if(!tmp.empty()) tmp.pop_back();
            }
            else{
                tmp.push_back(words[i]);
            }
        }
        string s;
        for (auto word:tmp){
            s+='/'+word;
        }
        if (s.empty()) s+='/';
        return s;
    }
    vector<string> split(string path){
        vector<string> res;
        string s;
        for (auto c:path){
            if (c=='/'){
                if(s.empty()) continue;
                res.push_back(s);
                s.clear();
            }
            else s+=c;
        }
        if(!s.empty()) res.push_back(s);
        return res;
    }
};
// @lc code=end
int main(){
    string path="/a//b////c/d//././/..";
    Solution t;
    t.simplifyPath(path);
}
