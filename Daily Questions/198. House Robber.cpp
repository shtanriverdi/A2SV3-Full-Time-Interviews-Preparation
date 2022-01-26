// Question Link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        nums.push_back(0);
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[len - 2] = nums[len - 2];
        for (int i = len - 3; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        } 
        return dp[0];
    }
};