// Question Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> valCountMap;
        unordered_set<int> usedSet;
        for (int &num : nums) {
            valCountMap[num]++;
        }
        
        int result = 0;
        for (auto &it : valCountMap) {
            int b = k - it.first;
            if (valCountMap.find(b) != valCountMap.end() && usedSet.find(b) == usedSet.end()) {
                result += (b == it.first) ? valCountMap[b] / 2 : min(valCountMap[b], it.second);
                usedSet.insert(b);
                usedSet.insert(it.first);
            }
        }
        
        return result;
    }
};