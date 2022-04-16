// Question Link: https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int len = cost.size();
        
        vector<int> dp(len, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < len; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        
        return dp.back();
    }
};

// Python3 Version
/*
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        
        n = len(cost)
        
        dp = [0] * n
        dp[0] = cost[0]
        dp[1] = cost[1]
        
        for i in range(n):
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

        return dp[-1]
*/
