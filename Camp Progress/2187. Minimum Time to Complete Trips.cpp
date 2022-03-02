// Question Link: https://leetcode.com/problems/minimum-time-to-complete-trips/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 10e13, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (isEnough(m, time, totalTrips)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        
        return l;
    }
    
    bool isEnough(long long curT, vector<int> &time, int totalTrips) {
        long long tripSum = 0;
        for (int &t : time) {
            tripSum += curT / t;
        }
        
        return tripSum >= totalTrips;
    }
};