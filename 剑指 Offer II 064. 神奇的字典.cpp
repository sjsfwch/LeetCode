#include "headers.h"

class MagicDictionary {
   private:
    unordered_map<int, vector<string>> _dictionary;

   public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (auto& s : dictionary) {
            if (_dictionary.find(s.size()) == _dictionary.end())
                _dictionary[s.size()] = vector<string>();
            _dictionary[s.size()].push_back(s);
        }
    }

    bool search(string searchWord) {
        if (_dictionary.find(searchWord.size()) == _dictionary.end())
            return false;
        for (auto& s : _dictionary[searchWord.size()]) {
            if (isValid(s, searchWord)) return true;
        }
        return false;
    }
    bool isValid(const string& str1, const string& str2) {
        bool flag = false;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                if (flag)
                    return false;
                else
                    flag = true;
            }
        }
        return flag;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */