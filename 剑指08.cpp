#include "headers.h"
using namespace std;

class CQueue {
public:
    // s1保存逆序的数，s2保存顺序的数
    stack<int> s1,s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (!s2.empty()) {int ret=s2.top();s2.pop();return ret;}
        else if(!s1.empty()){
            // 把s1里的数据全部放到s2里
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int ret=s2.top();
            s2.pop();
            return ret;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */