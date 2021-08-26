#include "headers.h"

class MyCalendar {
   private:
    map<int, int> _calendar;

   public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = _calendar.lower_bound(start);
        if (it != _calendar.end() && it->first < end) return false;
        if (it != _calendar.begin() && (--it)->second > start) return false;
        _calendar[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    MyCalendar m;
    vector<vector<int>> tmp = {{47, 50}, {33, 41}, {39, 45}, {33, 42},
                               {25, 32}, {26, 35}, {19, 25}, {3, 8},
                               {8, 13},  {18, 27}};
    for (auto &v : tmp) m.book(v[0], v[1]);
    return 0;
}