// Question Link: https://leetcode.com/problems/h-index/

// O(N + K) Solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> counts(1001, 0);
        for (int &citation : citations) {
            counts[citation]++;
        }        
        
        vector<int> sorted;
        for (int i = 1000; i >= 0; i--) {
            while (counts[i] > 0) {
                sorted.push_back(i);
                counts[i]--;
            }
        }

        int hIndex = 0;
        for (; hIndex < sorted.size(); hIndex++) {
            if (sorted[hIndex] < hIndex + 1) {
                break;
            }
        }
        
        return hIndex;
    }
};

// O(NlogN) Solution
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
