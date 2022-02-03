// Question Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int len = nums.size();
        // Prefix Sum Array
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        int result = 0, firstSum;
        for (int i = 0; (i + firstLen - 1) < len; i++) {
            firstSum = nums[i + firstLen - 1] - ( (i - 1) >= 0 ? (nums[i - 1]) : 0);
            int maxSecondSum = max(
                getMaxSumSecondWindow(nums, i + firstLen, len, secondLen),
                getMaxSumSecondWindow(nums, 0, i, secondLen)
            ); 
            result = max(maxSecondSum + firstSum, result);
        }
        
        return result;
    }
    
    int getMaxSumSecondWindow(vector<int> &nums, int startIndex, int &endIndex, int &secondWindowLen) {
        int maxSum = 0, curWindowSum;
        for (int i = startIndex; i + secondWindowLen - 1 < endIndex; i++) {
            curWindowSum = nums[i + secondWindowLen - 1] - ( (i - 1) >= 0 ? (nums[i - 1]) : 0 );
            maxSum = max(maxSum, curWindowSum);
        }
        return maxSum;
    }
};