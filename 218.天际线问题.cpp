/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return vector<vector<int>>();
        vector<int> tmp((*buildings.rbegin())[1], 0);
        for (int i = 0; i < buildings.size(); i++) {
            for (int j = buildings[i][0]; j < buildings[i][1]; j++) {
                if (j < tmp.size()) {
                    tmp[j] = max(tmp[j], buildings[i][2]);
                } else {
                    tmp.push_back(buildings[i][2]);
                }
            }
        }
        vector<vector<int>> res;
        int last = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != last) {
                res.push_back(vector<int>({i, tmp[i]}));
                last = tmp[i];
            }
        }
        return res;
    }
};
// @lc code=end
