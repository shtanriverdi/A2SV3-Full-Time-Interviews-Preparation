// Question Link: https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> letterCountMap;
        for (char c : s) {
            letterCountMap[c]++;
        }
        
        priority_queue<vector<int>> PQ;
        for (auto &it : letterCountMap) {
            PQ.push({ it.second, it.first });
        }
        
        string result = "";
        for (; !PQ.empty(); PQ.pop()) {
            int count = PQ.top()[0];
            while (count-- > 0) {
                result += (char)PQ.top()[1];
            }
        }
        
        return result;
    }
};