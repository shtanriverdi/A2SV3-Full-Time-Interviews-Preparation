// Question Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> counts(100001, 0);
        for (int &num : nums) {
            counts[num]++;
        }
        
        vector<int> sorted;
        for (int i = 0; i < 100001; i++) {
            while (counts[i] > 0) {
                sorted.push_back(i);
                counts[i]--;
            }
        }
        
        int minPairSum = -1, len = sorted.size();
        for (int i = 0; i < len / 2; i++) {
            minPairSum = max(minPairSum, sorted[len - i - 1] + sorted[i]);
        }
        
        return minPairSum;
    }
};