#include "headers.h"
using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> hash(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                int b = words[i][j] - 'a';
                hash[i] |= (1 << b);
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((hash[i] & hash[j]) == 0)
                    res = max(int(words[i].size() * words[j].size()), res);
            }
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    t.maxProduct(words);
    return 0;
}