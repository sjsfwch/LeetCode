#include "headers.h"

struct TrieNode {
    bool isend;
    int val;
    unordered_map<char, TrieNode*> next;
    TrieNode() {
        isend = false;
        val = 0;
    }
    void insert(char c) { next[c] = new TrieNode(); }
    bool find(char c) { return next.find(c) != next.end(); }
    bool isleaf() { return isend; }
};

class Trie {
   private:
    TrieNode* _root;

   public:
    /** Initialize your data structure here. */
    Trie() { _root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word, int val) {
        auto p = _root;
        for (auto& c : word) {
            if (!p->find(c)) p->insert(c);
            p = p->next[c];
        }
        p->isend = true;
        p->val = val;
    }
    int calWordsSumByPrefix(string prefix) {
        int res=0;
        auto p = _root;
        for (auto& c : prefix) {
            if (!p->find(c)) return res;
            p = p->next[c];
        }
        dfs(p, res);
        return res;
    }
    void dfs(TrieNode* root, int& res) {
        if (root->next.empty()) {
            res += root->val;
            return;
        }
        if (root->isend) res += root->val;
        for (auto it = root->next.begin(); it != root->next.end(); ++it)
            dfs(it->second, res);
    }
};

class MapSum {
   private:
    Trie* _trie;

   public:
    /** Initialize your data structure here. */
    MapSum() { _trie = new Trie(); }

    void insert(string key, int val) { _trie->insert(key, val); }

    int sum(string prefix) { return _trie->calWordsSumByPrefix(prefix); }
};