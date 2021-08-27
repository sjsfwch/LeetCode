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

   public:
    /** Initialize your data structure here. */
    Trie() { _root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = _root;
        for (auto& c : word) {
            if (!p->find(c)) p->insert(c);
            p = p->next[c];
        }
        p->isend = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = _root;
        for (auto& c : word) {
            if (!p->find(c)) return false;
            p = p->next[c];
        }
        return p->isend;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto p = _root;
        for (auto& c : prefix) {
            if (!p->find(c)) return false;
            p = p->next[c];
        }
        return true;
    }
};