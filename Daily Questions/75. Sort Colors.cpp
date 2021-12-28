// Question Link: https://leetcode.com/problems/sort-colors/

// Better One Pass Two Pointers Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, start = 0, end = nums.size() - 1;
        while (i <= end) {
            if (nums[i] == 0) {
                swap(nums[i], nums[start++]);
                if (i < start) {
                    i = start;
                }
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[end--]);
            }
            else {
                i++;
            }
        }
    }
};

// Initial Two Pass Counting Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for (int &num : nums) {
            counts[num]++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            while(counts[i] > 0) {
                nums[idx] = i;
                idx++;
                counts[i]--;
            }
        }
    }
};