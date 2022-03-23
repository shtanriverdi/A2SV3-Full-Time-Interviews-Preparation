// Question Link: https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> chrRangeMap;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (chrRangeMap.find(s[i]) == chrRangeMap.end()) {
                chrRangeMap[s[i]] = { 501, -1 };
            }
            chrRangeMap[s[i]] = { min(chrRangeMap[s[i]][0], i), max(chrRangeMap[s[i]][1], i) };
        }
        
        vector<vector<int>> ranges;
        for (auto &it : chrRangeMap) {
            ranges.push_back(it.second);
        }
        
        sort(begin(ranges), end(ranges));
        
        vector<vector<int>> mergedRanges = { ranges[0] };
        for (int i = 1; i < ranges.size(); i++) {
            int prevStart = mergedRanges.back()[0];
            int prevEnd = mergedRanges.back()[1];
            
            int curStart = ranges[i][0];
            int curEnd = ranges[i][1];
            
            if (prevEnd > curStart) {
                mergedRanges.back() = { min(prevStart, curStart), max(prevEnd, curEnd) };
            }
            else {
                mergedRanges.push_back( ranges[i] );
            }
        }
        
        vector<int> result;
        for (vector<int> &range : mergedRanges) {
            result.push_back(range[1] - range[0] + 1);
        }
        
        return result;
    }
};