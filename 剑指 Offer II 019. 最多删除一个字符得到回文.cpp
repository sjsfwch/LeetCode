#include "headers.h"

class Solution {
   public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi])
                return isPalindrome(s, lo + 1, hi) ||
                       isPalindrome(s, lo, hi - 1);
            lo++;
            hi--;
        }
        return true;
    }
    bool isPalindrome(string s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};