/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> rot;
        vector<vector<int>> t(m, vector<int>(n, 0));
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    rot.push(make_pair(i, j));
            }
        }
        int res = 0;
        while (!rot.empty()) {
            auto orange = rot.front();
            rot.pop();
            for (int i = 0; i < 4; ++i) {
                int x = orange.first + dx[i], y = orange.second + dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                    continue;
                t[x][y] = t[orange.first][orange.second] + 1;
                res = t[x][y];
                grid[x][y] = 2;
                count--;
                if (count == 0) return res;
                rot.push(make_pair(x, y));
            }
        }
        return count == 0 ? res : -1;
    }
};
// @lc code=end
