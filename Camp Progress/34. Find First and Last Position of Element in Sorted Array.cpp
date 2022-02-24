// Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftMostIndex = binarySearch(nums, target, true);
        int rightMostIndex = binarySearch(nums, target, false);
        
        return { leftMostIndex, rightMostIndex };
    }
    
    int binarySearch(vector<int>& nums, int target, bool flag) {
        int l = 0, r = nums.size() - 1, mid, best = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                best = mid;
                if (flag) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if (target < nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return best;
    }
};