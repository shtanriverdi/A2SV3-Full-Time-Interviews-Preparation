// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        
        int l = 0, s = 1, r = 1;
        while (r < len) {
            if (nums[l] != nums[r]) {
                swap(nums[s], nums[r]);
                l++;
                s++;
            }
            r++;
        }
        
        return l + 1;
    }
};