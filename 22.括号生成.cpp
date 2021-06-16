/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> res;
    string current="";
    vector<string> generateParenthesis(int n) {
        DFS(0,0,n);
        return res;
    }
    void DFS(int left,int right,int n){
        if(right>left) return;
        if(left>n) return;
        if (left==right&&left==n) {res.push_back(current);return;}
        current.push_back('(');
        DFS(left+1,right,n);
        current.pop_back();
        current.push_back(')');
        DFS(left,right+1,n);
        current.pop_back();
    }
};
// @lc code=end

int main(){
    Solution t;
    t.generateParenthesis(1);
    return 0;
}