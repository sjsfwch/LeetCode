/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, tmp;
        int i = 0, len = 0, space = 0, avgspace = 0, extraspace = 0;
        while (i < words.size()) {
            while (i < words.size() &&
                   len + words[i].size() <= maxWidth) {
                len += words[i].size();
                tmp.push_back(words[i]);
                // 加个空格
                len++;
                i++;
            }
            // 最后一个空格减掉
            len--;
            space = maxWidth - len;
            avgspace = space / (max(int(tmp.size()-1),1));
            extraspace=space%(max(int(tmp.size()-1),1));
            string s;
            if (i != words.size()) {
                for (int j = 0; j < tmp.size(); j++) {
                    s += tmp[j];
                    // 最后一个词
                    if (j == tmp.size() - 1) {
                        // 只有一个词
                        if (tmp.size() == 1) {
                            while (s.size() < maxWidth) s += ' ';
                        }
                    } else {
                        // 至少1个空格
                        s += ' ';
                        // 加平均的空格
                        for (int k = 0; k < avgspace; k++) s += ' ';
                        // 额外的空格
                        if (extraspace-- > 0) s += ' ';
                    }
                }
                res.push_back(s);
                tmp.clear();
                len = 0;
            }
            // 最后一行左对齐
            else {
                for (int j = 0; j < tmp.size(); j++) s += tmp[j] + ' ';
                s.pop_back();
                while (s.size() < maxWidth) s += ' ';
                res.push_back(s);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution t;
    vector<string> words = {
        "This", "is", "an", "example", "of", "text", "justification."};
    t.fullJustify(words, 16);
    return 0;
}