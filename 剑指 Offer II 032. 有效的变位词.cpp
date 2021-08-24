#include "headers.h"

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s == t) return false;
        if (s.size() != t.size()) return false;
        vector<int> chars(26, 0);
        for (auto &c : s) chars[c - 'a']++;
        for (auto &c : t) {
            if (chars[c - 'a'] == 0) return false;
            chars[c - 'a']--;
        }
        return true;
    }
};