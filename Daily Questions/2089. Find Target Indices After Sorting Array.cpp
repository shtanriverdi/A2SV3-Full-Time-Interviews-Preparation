// Question Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/

// Better Solution
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> counts(101, 0);
        unordered_set<int> targetIndices;
        for (int &num : nums) {
            counts[num]++;
            // Target found
            if (num == target) {
                targetIndices.insert(num);
            }
        }
        int index = 0;
        for (int i = 0; i < 101; i++) {
            while (counts[i] > 0) {
                if (targetIndices.find(i) != targetIndices.end()) {
                    result.push_back(index);
                }
                index++;
                counts[i]--;
            }
        }
        return result;
    }
};

// Initial Solution
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        // Count Sort
        countSort(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }
        return result;
    }
    
    void countSort(vector<int> &nums) {
        vector<int> counts(101, 0);
        for (int &num : nums) {
            counts[num]++;
        }
        int index = 0;
        for (int i = 0; i < 101; i++) {
            while (counts[i] > 0) {
                nums[index] = i;
                counts[i]--;
                index++;
            }
        }
    }
};