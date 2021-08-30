#include "headers.h"

class Solution {
   private:
    vector<int> _hash;

   public:
    Solution(vector<int>& w) {
        _hash = vector<int>(w.size(), 0);
        _hash[0] = w[0];
        for (int i = 1; i < w.size(); ++i) _hash[i] = _hash[i - 1] + w[i];
    }

    int pickIndex() {
        int r = rand() % _hash.back();
        int p = upper_bound(_hash.begin(), _hash.end(), r) - _hash.begin();
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
    vector<int> w = {1, 2, 3, 4};
    Solution t(w);
    vector<int> res(4, 0);
    for (int i = 0; i < 100000; ++i) {
        res[t.pickIndex()]++;
    }
    for_each(res.begin(), res.end(),
             [](const int i) { cout << i / 100000.0 << ' '; });
    return 0;
}