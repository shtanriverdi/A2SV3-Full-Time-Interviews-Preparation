// Question Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int L = 0, R = 0, result = 0, len = nums.size(), avg, windownLen;
        long preSum = k;
        for (; R < len; R++) {
            preSum += nums[R];
            windownLen = (R - L + 1);
            avg = preSum / (R - L + 1);
            if (nums[R] > avg) {
                preSum -= nums[L];
                L++;
            }
            result = max(result, (R - L + 1));
        }
        
        return result;
    }
};