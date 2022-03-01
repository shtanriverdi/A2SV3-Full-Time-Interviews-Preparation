// Question Link: https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        return binarySearch(nums, 0, len - 1, len);
    }
    
    int binarySearch(vector<int> &nums, int l, int r, int &len) {
        if (l > r) {
            return -1;
        }
        
        int m = l + (r - l) / 2;
        
        int lNeighbor = (m - 1 >= 0) ? nums[m - 1] : INT_MIN;
        int rNeighbor = (m + 1 < len) ? nums[m + 1] : INT_MIN;
        
        if (nums[m] >= lNeighbor && nums[m] >= rNeighbor) {
            return m;
        }
        
        if (lNeighbor > rNeighbor) {
            return binarySearch(nums, l, m - 1, len);
        }
        return binarySearch(nums, m + 1, r, len);
    }
};