// Question Link: https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int counts[101] = { 0 };
        for (int &num : nums) {
            counts[num]++;
        }
        int result = 0;
        for (int &count : counts) {
            result += (count * (count - 1)) / 2;
        }
        return result;
    }
};