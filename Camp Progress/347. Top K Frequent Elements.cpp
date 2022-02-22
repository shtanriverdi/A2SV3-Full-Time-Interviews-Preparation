// Question Link: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countsMap;
        for (int &num : nums) {
            countsMap[num]++;
        }
        
        priority_queue<vector<int>> countPQ;
        for (auto &it : countsMap) {
            countPQ.push({ -1 * it.second, it.first });
            if (countPQ.size() > k) {
                countPQ.pop();
            }
        }
        
        vector<int> result;
        for (; !countPQ.empty(); countPQ.pop()) {
            result.push_back(countPQ.top()[1]);
        }
        
        return result;
    }
};