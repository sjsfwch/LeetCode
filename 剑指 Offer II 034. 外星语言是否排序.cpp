#include "headers.h"

class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orders;
        for (int i = 0; i < order.size(); ++i) orders[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!isValid(words[i], words[i + 1], orders)) return false;
        }
        return true;
    }
    bool isValid(string str1, string str2, unordered_map<char, int>& orders) {
        for (int i = 0; i < str1.size() && i < str2.size(); ++i) {
            if (orders[str1[i]] > orders[str2[i]])
                return false;
            else if (orders[str1[i]] < orders[str2[i]])
                return true;
        }
        return str1.size() <= str2.size();
    }
};
int main() {
    Solution t;
    vector<string> words = {"hello", "leetcode"};
    t.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz");
    return 0;
}