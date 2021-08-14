#include "headers.h"
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int bi = 0, bj = 0, c = 0, cur = 0;
        string res;
        while (j >= 0 && i >= 0) {
            bi = a[i] - '0';
            bj = b[j] - '0';
            cur = (bi + bj + c) % 2;
            c = (bi + bj + c) / 2;
            res = char(cur + '0') + res;
            i--;
            j--;
        }
        while (i >= 0) {
            bi = a[i] - '0';
            cur = (bi + c) % 2;
            c = (bi + c) / 2;
            res = char(cur + '0') + res;
            i--;
        }
        while (j >= 0) {
            bj = b[j] - '0';
            cur = (bj + c) % 2;
            c = (bj + c) / 2;
            res = char(cur + '0') + res;
            j--;
        }
        if (c == 1) res = '1' + res;
        if (res[0] == '0' && res.size() > 1) res.erase(0, 1);
        return res;
    }
};

int main() {
    Solution t;
    t.addBinary("11", "10");
    return 0;
}