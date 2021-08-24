#include "headers.h"

class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        auto cmp = [](const string& time1, const string& time2) {
            int hour1 = stoi(time1.substr(0, 2)),
                hour2 = stoi(time2.substr(0, 2));
            if (hour1 < hour2)
                return true;
            else if (hour1 > hour2)
                return false;
            int min1 = stoi(time1.substr(3, 2)),
                min2 = stoi(time2.substr(3, 2));
            return min1 <= min2;
        };
        auto diff = [](const string& time1, const string& time2) {
            int hour1 = stoi(time1.substr(0, 2)),
                hour2 = stoi(time2.substr(0, 2));
            int min1 = stoi(time1.substr(3, 2)),
                min2 = stoi(time2.substr(3, 2));
            int res1 = abs(hour1 * 60 + min1 - hour2 * 60 - min2);
            int res2 = abs(res1 - 1440);
            return min(res1, res2);
        };
        sort(timePoints.begin(), timePoints.end(), cmp);
        int res = INT32_MAX;
        for (int i = 0; i < timePoints.size() - 1; ++i) {
            res = min(res, diff(timePoints[i], timePoints[i + 1]));
        }
        res = min(res, diff(timePoints.front(), timePoints.back()));
        return res;
    }
};