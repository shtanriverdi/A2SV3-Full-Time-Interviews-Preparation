// Question Link: https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> valueCountMap;
        for (int &n : arr) {
            valueCountMap[n]++;
        }
        
        priority_queue<int> countsPQ;
        for (auto &it : valueCountMap) {
            countsPQ.push(it.second);
        }
        
        int result = 0, half = arr.size() / 2;
        while (half > 0) {
            half -= countsPQ.top();
            countsPQ.pop();
            result++;
        }
        
        return result;
    }
};