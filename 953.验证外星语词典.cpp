/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> index;
        for (int i = 0; i < order.size(); ++i) index[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i], word2 = words[i + 1];
            int j = 0, flag = 0;
            while (j < word1.size() && j < word2.size()) {
                if (index[word1[j]] > index[word2[j]])
                    return false;
                else if (index[word1[j]] < index[word2[j]]) {
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 0 && word1.size() > word2.size()) return false;
        }
        return true;
    }
};
// @lc code=end
