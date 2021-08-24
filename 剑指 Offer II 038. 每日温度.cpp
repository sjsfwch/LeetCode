#include "headers.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // temperature,index
        stack<pair<int,int>> tmp;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();++i){
            int cur=temperatures[i];
            while((!tmp.empty())&&tmp.top().first<cur){
                auto t=tmp.top();
                tmp.pop();
                res[t.second]=i-t.second;
            }
            tmp.push(make_pair(cur,i));
        }
        return res;
    }
};