// Question Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> valIdxMap;
        for (int i = 0, wanted; i < numbers.size(); i++) {
            wanted = target - numbers[i];
            if (valIdxMap.find(wanted) != valIdxMap.end()) {
                return { valIdxMap[wanted] + 1, i + 1 };
            }
            valIdxMap[numbers[i]] = i;
        }
        return { 1453, 1071 };
    }
};