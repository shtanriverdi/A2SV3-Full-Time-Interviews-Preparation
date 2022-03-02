// Question Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            int lVal = nums[l], mVal = nums[m], rVal = nums[r];
            
            // If any l, r or m is equal to target
            if (target == lVal || target == mVal || target == rVal) {
                return target == lVal ? l : (target == rVal ? r : m);
            }
            
            // If left part is sorted
            if (lVal <= mVal) {
                // If target is possible in sorted part, go to that part
                if (target >= lVal && target <= mVal) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            // If right part is sorted
            else if (mVal <= rVal) {
                // If target is possible in sorted part, go to that part
                if (target >= mVal && target <= rVal) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
        }
        
        return -1;
    }
};