// Question Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

// O(N)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            nums[i] += nums[i - 1];
        }
        int A = getMaxSum(nums, len, firstLen, secondLen);
        int B = getMaxSum(nums, len, secondLen, firstLen);
        return max(A, B);
    }
    
    int getMaxSum(vector<int> &nums, int &len, int f, int s) {
        int maxFirstWindowSum = 0, maxSum = 0;
        for (int i = 0; (i + f + s - 1) < len; i++) {
            maxFirstWindowSum = max(maxFirstWindowSum, nums[i + f - 1] - (i - 1 >= 0 ? nums[i - 1] : 0));
            int secondWindowCurSum = nums[i + f + s - 1] - ((i + f - 1) >= 0 ? nums[i + f - 1] : 0);
            maxSum = max(maxSum, maxFirstWindowSum + secondWindowCurSum);
        }
        return maxSum;
    }
};

// O(N^2)
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
