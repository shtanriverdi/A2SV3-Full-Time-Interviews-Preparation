// Question Link: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int &num : nums) {
            countMap[num]++;
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> countValPQ;
        for (auto it : countMap) {
            countValPQ.push({ it.second, it.first });
            if (countValPQ.size() > k) {
                countValPQ.pop();
            }
        }
        
        vector<int> result;
        for (; !countValPQ.empty(); countValPQ.pop()) {
            result.push_back(countValPQ.top()[1]);
        }
        
        return result;
    }
};