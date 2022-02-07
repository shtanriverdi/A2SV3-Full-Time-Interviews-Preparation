// Question Link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixRight = nums;
        for (int i = 0; i < len; i++) {
            prefixRight[i] *= (i - 1 >= 0 ? prefixRight[i - 1] : 1);
        }

        vector<int> prefixLeft = nums;
        for (int i = len - 1; i >= 0; i--) {
            prefixLeft[i] *= (i + 1 < len ? prefixLeft[i + 1] : 1);
        }
        
        vector<int> result(len, 0);
        for (int i = 0; i < len; i++) {
            result[i] = (i - 1 >= 0 ? prefixRight[i - 1] : 1) * (i + 1 < len ? prefixLeft[i + 1] : 1);
        }
        
        return result;
    }
};