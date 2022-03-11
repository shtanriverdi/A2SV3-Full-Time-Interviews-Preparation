// Question Link: https://leetcode.com/contest/weekly-contest-120/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int &n : nums) {
            n *= n;
        }
        sort(begin(nums), end(nums));
        return nums;
    }
};