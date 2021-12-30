// Question Link: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> result;
        int minIdx = 0, maxIdx = nums.size() - 1;
        int turn = minIdx;
        while (minIdx <= maxIdx) {
            result.push_back(nums[turn]);
            if (turn == minIdx) {
                turn = maxIdx;
                minIdx++;
                
            } else {
                turn = minIdx;
                maxIdx--;
            }
        }        
        return result;
    }
};
