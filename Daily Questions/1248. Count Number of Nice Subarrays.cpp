// Question Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> onesIndices;
        unordered_map<int, int> evensCntLeft;
        for (int i = 0, evens = 0; i < len; i++) {
            if (nums[i] % 2 == 0) {
                evens++;
            }
            else {
                onesIndices.push_back(i);
                evensCntLeft[i] = evens;
                evens = 0;
            }
        }
        
        unordered_map<int, int> evensCntRight;
        for (int i = len - 1, evens = 0; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                evens++;
            }
            else {
                evensCntRight[i] = evens;
                evens = 0;
            }
        }
        
        int result = 0;
        int start = 0, end = start + k - 1, onesLen = onesIndices.size();
        while (end < onesLen) {
            result += 1 
                + evensCntLeft[onesIndices[start]] 
                + evensCntRight[onesIndices[end]] 
                + (evensCntLeft[onesIndices[start]] * evensCntRight[onesIndices[end]]);
            start++;
            end++;
        }
        
        return result;
    }
};