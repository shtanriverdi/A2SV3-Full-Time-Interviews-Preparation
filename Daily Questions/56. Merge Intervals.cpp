// Question Link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int cur = 0, i = 0, n = intervals.size();
        while (cur < n) {
            vector<int> interval = intervals[cur];
            for (i = cur + 1; i < n && (intervals[i][0] <= interval[1]); i++) {
                    interval = { min(intervals[i][0], interval[0]), max(intervals[i][1], interval[1]) };
            }
            result.push_back(interval);
            cur = i;
        }
        return result;
    }
};