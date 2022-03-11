// Question Link: https://leetcode.com/contest/weekly-contest-120/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        
        vector<pair<int, char>> dp(len);
        dp[0] = { 1, '*' };
            
        for (int i = 1; i < len; i++) {
            int prevVal = arr[i - 1];
            int curVal = arr[i];
            char prevSign = dp[i - 1].second;
            
            if (prevVal == curVal) {
                dp[i] = { 1, (curVal > prevVal) ? '+' : '-' };
            }
            else {
                if (curVal > prevVal) {
                    dp[i] = { (prevSign == '+' ? 2 : dp[i - 1].first + 1), '+' };
                }
                else if (curVal < prevVal) { 
                    dp[i] = { (prevSign == '+' ? dp[i - 1].first + 1 : 2), '-' };
                }
                else {
                    dp[i] = { 0, '*' };
                }
            }
        }

        int maxTurb = 1;
        for (pair<int, char> &p : dp) {
            maxTurb = max(p.first, maxTurb);
        }
        
        return maxTurb;
    }
};