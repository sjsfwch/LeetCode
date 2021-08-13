/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include "headers.h"
// @lc code=start
class MedianFinder {
   private:
    // _max_heap < _min_heap
    // len(_max_heap) >= len(_min_heap)
    priority_queue<int> _max_heap;
    priority_queue<int, vector<int>, greater<int>> _min_heap;

   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        int max_heap_len = _max_heap.size(), min_heap_len = _min_heap.size();
        if (max_heap_len == min_heap_len) {
            _min_heap.push(num);
            _max_heap.push(_min_heap.top());
            _min_heap.pop();
        } else {
            _max_heap.push(num);
            _min_heap.push(_max_heap.top());
            _max_heap.pop();
        }
    }

    double findMedian() {
        if (_max_heap.empty()) return NULL;
        if (_max_heap.size() == _min_heap.size())
            return (_max_heap.top() + _min_heap.top()) * 0.5;
        else
            return double(_max_heap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main() {
    MedianFinder t;
    t.addNum(1);
    t.addNum(2);
    cout << t.findMedian() << endl;
    return 0;
}