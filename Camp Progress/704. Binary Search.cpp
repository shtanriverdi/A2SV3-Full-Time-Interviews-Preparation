// Question Link: https://leetcode.com/problems/binary-search/

// Recursive Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        return binarySearch(nums, target, 0, right);
    }
    
    int binarySearch(vector<int>& nums, int &target, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                return binarySearch(nums, target, mid + 1, right);
            }
            else {
                return binarySearch(nums, target, left, mid - 1);
            }
        }
        else {
            return -1;
        }
    }
};

// Iterative Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
