/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> order;
        for (auto word : words) {
            if (order.find(word) == order.end())
                order[word] = 1;
            else
                order[word] += 1;
        }
        vector<pair<string, int>> tmp;
        for (auto it : order) {
            tmp.push_back(make_pair(it.first, it.second));
        }
        sort(tmp.begin(), tmp.end(),
             [](const pair<string, int> a, const pair<string, int> b) {
                 if (a.second > b.second)
                     return true;
                 else if (a.second < b.second)
                     return false;
                 else
                     return a.first < b.first;
             });
        vector<string> res;
        int i = 0;
        while (i < k) {
            res.push_back(tmp[i].first);
            ++i;
        }
        return res;
    }
};
// @lc code=end

int main() {
    auto t = Solution();
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    t.topKFrequent(words, 2);
    return 0;
}