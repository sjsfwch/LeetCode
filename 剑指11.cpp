#include "headers.h"
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low=0,high=numbers.size()-1;
        while(low<high){
            int mid=(low+high)>>1;
            if (numbers[mid]>numbers[high]) low=mid+1;
            else if(numbers[mid]<numbers[high]) high=mid;
            else high--;
        }
        return numbers[low];
    }
};

int main(){
    vector<int> x={10,1,10,10,10};
    Solution s;
    int a= s.minArray(x);
    return 0;
}