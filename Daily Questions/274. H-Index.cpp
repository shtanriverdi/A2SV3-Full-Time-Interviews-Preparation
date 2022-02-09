// Question Link: https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations), greater<int>());
        int hIndex = 0;
        for (; hIndex < citations.size(); hIndex++) {
            if (citations[hIndex] < hIndex + 1) {
                break;
            }
        }
        
        return hIndex;
    }
};