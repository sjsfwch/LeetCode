#include "headers.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[key].emplace_back(str);
        }
        vector<vector<string>> ret;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            ret.emplace_back(it->second);
        }
        return ret;
    }
};

int main() {
    Solution t;
    vector<string> strs = {"", ""};
    t.groupAnagrams(strs);
    return 0;
}