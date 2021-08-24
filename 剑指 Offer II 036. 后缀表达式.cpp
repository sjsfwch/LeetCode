#include "headers.h"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                if (s == "+")
                    nums.push(num1 + num2);
                else if (s == "-")
                    nums.push(num2 - num1);
                else if (s == "*")
                    nums.push(num1 * num2);
                else
                    nums.push(num2 / num1);
            } else
                nums.push(stoi(s));
        }
        return nums.top();
    }
};