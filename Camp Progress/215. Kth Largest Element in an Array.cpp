// Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

// O(N + K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int counts[20001] = { 0 };
        for (int &num : nums) {
            counts[num + 10000]++;
        }
        
        vector<int> sorted;
        for (int i = 20000; i >= 0 ; i--) {
            while (counts[i]-- > 0) {
                sorted.push_back(i - 10000);
            }
        }
        
        return sorted[k - 1];
    }
};

// O(NlogN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k - 1];
    }
};
