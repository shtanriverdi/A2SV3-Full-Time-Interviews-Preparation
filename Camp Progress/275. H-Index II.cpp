// Question Link: https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, len = citations.size(), r = len - 1, m, bestHIndex = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            int HIndex = len - m;
            if (citations[m] >= HIndex) {
                bestHIndex = HIndex;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return bestHIndex;
    }
};