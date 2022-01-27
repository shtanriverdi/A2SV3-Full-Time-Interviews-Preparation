// Question Link: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int firstPartLen = len - k;
        vector<int> firstPart = { nums.begin(), nums.begin() + firstPartLen };
        vector<int> secondPart = { nums.begin() + firstPartLen, nums.end() };
        for (int i = 0; i < k; i++) {
            nums[i] = secondPart[i];
        }
        for (int i = k, j = 0; i < len; i++, j++) {
            nums[i] = firstPart[j];
        }
    }
};