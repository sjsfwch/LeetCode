#include "headers.h"

class KthLargest {
   private:
    priority_queue<int, vector<int>, greater<int>> _heap;
    int _size;

   public:
    KthLargest(int k, vector<int>& nums) {
        _size = k;
        for (auto& num : nums) {
            if (_heap.size() < _size) {
                _heap.push(num);
            } else if (num > _heap.top()) {
                _heap.pop();
                _heap.push(num);
            }
        }
    }

    int add(int val) {
        if (_heap.size() < _size) {
            _heap.push(val);
        } else if (val > _heap.top()) {
            _heap.pop();
            _heap.push(val);
        }
        return _heap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest tmp(3, nums);
    cout << tmp.add(3) << endl;
    cout << tmp.add(5) << endl;
    cout << tmp.add(10) << endl;
    cout << tmp.add(9) << endl;
    cout << tmp.add(4) << endl;
    return 0;
}