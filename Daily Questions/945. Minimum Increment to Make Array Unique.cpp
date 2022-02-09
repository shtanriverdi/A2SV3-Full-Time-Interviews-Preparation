// Question Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<long> counts(200002, 0);
        for (int &num : nums) {
            counts[num]++;
        }
        
        int minCost = 0;
        for (int i = 1; i < 200002; i++) {
            if (counts[i - 1] > 1) {
                minCost += counts[i - 1] - 1;
                counts[i] += counts[i - 1] - 1;
            } 
        }
        
        return minCost;
    }
};