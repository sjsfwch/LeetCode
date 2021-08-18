#include "headers.h"

class Solution {
   public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            while (lo < hi && !isalnum(s[lo])) lo++;
            while (lo < hi && !isalnum(s[hi])) hi--;
            if (tolower(s[lo++]) != tolower(s[hi--])) return false;
        }
        return true;
    }
};