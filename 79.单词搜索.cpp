/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        if (m * n < word.size()) return false;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    bool flag = dfs(board, word, 1, i, j, visit);
                    if (flag) return flag;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int cur, int i, int j,
             vector<vector<bool>>& visit) {
        if (cur == word.size()) return true;
        bool flag = false;
        // up
        if (i - 1 >= 0 && !visit[i - 1][j] && board[i - 1][j] == word[cur]) {
            visit[i - 1][j] = true;
            flag = dfs(board, word, cur + 1, i - 1, j, visit);
            if (flag) return flag;
            visit[i - 1][j] = false;
        }
        // down
        if (i + 1 < board.size() && !visit[i + 1][j] &&
            board[i + 1][j] == word[cur]) {
            visit[i + 1][j] = true;
            flag = dfs(board, word, cur + 1, i + 1, j, visit);
            if (flag) return flag;
            visit[i + 1][j] = false;
        }
        // left
        if (j - 1 >= 0 && !visit[i][j - 1] && board[i][j - 1] == word[cur]) {
            visit[i][j - 1] = true;
            flag = dfs(board, word, cur + 1, i, j - 1, visit);
            if (flag) return flag;
            visit[i][j - 1] = false;
        }
        // right
        if (j + 1 < board[0].size() && !visit[i][j + 1] &&
            board[i][j + 1] == word[cur]) {
            visit[i][j + 1] = true;
            flag = dfs(board, word, cur + 1, i, j + 1, visit);
            if (flag) return flag;
            visit[i][j + 1] = false;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution t;
    // vector<vector<char>> board = {
    //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    vector<vector<char>> board = {{'a', 'a'}};
    cout << t.exist(board, "aaa");
    return 0;
}