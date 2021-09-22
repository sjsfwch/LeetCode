#include "headers.h"

class Solution {
   private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int a = 0;
                    search(grid, a, i, j);
                    max_area = max(max_area, a);
                }
            }
        }
        return max_area;
    }
    void search(vector<vector<int>>& grid, int& area, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != 1)
            return;
        area++;
        grid[i][j] = -1;
        for (int k = 0; k < 4; ++k) {
            search(grid, area, i + dx[k], j + dy[k]);
        }
    }
};