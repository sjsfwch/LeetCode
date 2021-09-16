/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include "headers.h"
// @lc code=start

struct TrieNode {
    bool isend = false;
    TrieNode* next[26] = {nullptr};
};

void insert_word(TrieNode* root, string word) {
    auto p = root;
    for (auto c : word) {
        if (!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
        p = p->next[c - 'a'];
    }
    p->isend = true;
}

class Solution {
   private:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> res;
        string cur;
        TrieNode* root = new TrieNode();
        for (auto& word : words) insert_word(root, word);
        unordered_set<string> tmpres;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (root->next[board[i][j] - 'a']) {
                    string s = "";
                    s += board[i][j];
                    dfs(board, i, j, root->next[board[i][j]], s, tmpres);
                }
            }
        }
        res.assign(tmpres.begin(), tmpres.end());
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root,
             string cur, unordered_set<string>& tmpres) {
        if (!root) return;
        if (cur.size() > 10) return;
        if (root->isend) tmpres.insert(cur);
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
                board[x][y] != '#') {
                char next = board[x][y];
                board[x][y] = '#';
                dfs(board, x, y, root->next[next - 'a'], cur + next, tmpres);
                board[x][y] = next;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution t;
    // vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
    //                               {'e', 't', 'a', 'e'},
    //                               {'i', 'h', 'k', 'r'},
    //                               {'i', 'f', 'l', 'v'}};
    vector<vector<char>> board = {{'a'}};
    vector<string> words = {"a"};
    t.findWords(board, words);
    return 0;
}