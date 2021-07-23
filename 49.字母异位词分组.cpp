/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (hashMap.find(key) == hashMap.end())
                hashMap[key] = vector<string>();
            hashMap[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it : hashMap) {
            res.push_back(it.second);
        }
        return res;
    }
};
// @lc code=end
