/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "headers.h"
// @lc code=start
class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> _s, _mins;
    MinStack() {}

    void push(int val) {
        _s.push(val);
        if (_mins.empty() || _mins.top() > val)
            _mins.push(val);
        else
            _mins.push(_mins.top());
    }

    void pop() {
        _s.pop();
        _mins.pop();
    }

    int top() { return _s.top(); }

    int getMin() { return _mins.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
