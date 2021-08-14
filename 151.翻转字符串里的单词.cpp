/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        string res = "";
        int start = s.size() - 1, end = s.size() - 1;
        while (start >= 0 && end >= 0) {
            while (end >= 0 && s[end] == ' ') end--;
            if (end < 0) break;
            start = end;
            while (start >= 0 && s[start] != ' ') start--;
            start++;
            res += s.substr(start, end - start + 1);
            res += ' ';
            end = start - 1;
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

int main() {
    Solution t;
    t.reverseWords("  hello world  ");
    return 0;
}