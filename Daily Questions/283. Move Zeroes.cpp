// Question Link: https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[idx++]);
            }
        }
    }
};