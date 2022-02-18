// Question Link: https://leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len, INT_MIN);
        dp[0] = nums[0];

        // Fill the window initially
        deque<vector<int>> monoDecreasingDeque;
        monoDecreasingDeque.push_back({ dp[0], 0 }); // { value, index }

        for (int i = 1; i < len; i++) {
            // Remove indices ourside our range
            while (!monoDecreasingDeque.empty() && monoDecreasingDeque.front()[1] < i - k) {
                monoDecreasingDeque.pop_front();
            }

            dp[i] = nums[i] + monoDecreasingDeque.front()[0];

            // Update monotonic decrasing deque values
            while (!monoDecreasingDeque.empty() && dp[i] > monoDecreasingDeque.back()[0]) {
                monoDecreasingDeque.pop_back();
            }

            monoDecreasingDeque.push_back({ dp[i], i });
        }

        return dp[len - 1];
    }
};