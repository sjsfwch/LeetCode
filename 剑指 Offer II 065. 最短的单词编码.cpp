#include "headers.h"

struct TrieNode {
    bool isend;
    unordered_map<char, TrieNode*> next;
    TrieNode() { isend = false; }
    void insert(char c) { next[c] = new TrieNode(); }
    bool find(char c) { return next.find(c) != next.end(); }
    bool isleaf() { return isend; }
};

class Trie {
   private:
    TrieNode* _root;
    int _charsize;

   public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new TrieNode();
        _charsize = 0;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = _root;
        for (int i = word.size() - 1; i > -1; --i) {
            auto c = word[i];
            if (!p->find(c)) {
                p->insert(c);
                _charsize++;
            }
            p = p->next[c];
        }
        p->isend = true;
    }
    int getSize() {
        int size = 0;
        dfs(_root, 0, size);
        return size;
    }

    void dfs(TrieNode* root, int len, int& size) {
        if (root->next.empty()) {
            size += len + 1;
            return;
        }
        for (auto it = root->next.begin(); it != root->next.end(); ++it)
            dfs(it->second, len + 1, size);
    }
};

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        auto trie = new Trie();
        for (auto& s : words) trie->insert(s);
        return trie->getSize();
    }
};