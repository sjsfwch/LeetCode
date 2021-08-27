#include "headers.h"

void split_string(const std::string& s, std::vector<std::string>& v,
                  const std::string& c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) v.push_back(s.substr(pos1));
}

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
    int search(string word) {
        int count = 0;
        auto p = _root;
        for (auto& c : word) {
            if (!p->find(c)) return 0;
            p = p->next[c];
            count++;
            if (p->isend) return count;
        }
        return count;
    }
};

class Solution {
   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto trie = new Trie();
        for (auto& s : dictionary) trie->insert(s);
        vector<string> words;
        split_string(sentence, words, " ");
        string res = "";
        for (auto& word : words) {
            auto len = trie->search(word);
            if (len != 0)
                res += word.substr(0, len);
            else
                res += word;
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};