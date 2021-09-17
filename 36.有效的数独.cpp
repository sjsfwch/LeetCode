/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9], column[9], box[9];
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        memset(box, 0, sizeof(box));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '0';
                // check row
                if ((row[i] >> n) & 1) return false;
                row[i] |= 1 << n;
                // check column
                if ((column[j] >> n) & 1) return false;
                column[j] |= 1 << n;
                // check box
                int box_idx = i / 3 + j / 3 * 3;
                if ((box[box_idx] >> n) & 1) return false;
                box[box_idx] |= 1 << n;
            }
        }
        return true;
    }
};
// @lc code=end
