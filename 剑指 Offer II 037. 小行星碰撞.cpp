#include "headers.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> tmp;
        vector<int> res;
        int i = 0;
        for (auto& n : asteroids) {
            if (n > 0)
                tmp.push(n);
            else {
                while ((!tmp.empty()) && tmp.top() < -n) tmp.pop();
                if (tmp.empty())
                    res.push_back(n);
                else if (tmp.top() == -n)
                    tmp.pop();
            }
        }
        int start = res.size();
        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }
        int end = res.size() - 1;
        while (start < end) swap(res[start++], res[end--]);
        return res;
    }
};

int main() {
    Solution t;
    vector<int> num = {-2, -1, 1, 2};
    t.asteroidCollision(num);
    return 0;
}