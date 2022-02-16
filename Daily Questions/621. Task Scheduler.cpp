// Question Link: https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letterCounts(26, 0);
        for (char task : tasks) {
            letterCounts[task - 'A']++;
        }
        
        vector<int> counts;
        for (int &count : letterCounts) {
            if (count > 0) {
                counts.push_back(count);
            }
        } 
        
        sort(begin(counts), end(counts), greater<int>());
        
        // Maximum count
        int maxCount = counts[0];
        // Initial Possible Longest Length
        int len = ((maxCount * n) + maxCount) - n;
        // Initial empty slots in the middle
        int slots = (maxCount * n) - n;
        
        for (int i = 1; i < counts.size(); i++) {
            int cnt = counts[i];
            if (cnt == maxCount) {
                if (slots > 0) {
                    len++;
                    slots -= cnt - 1;
                }
                else {
                    len += cnt;
                }
            }
            else {
                if (slots >= cnt) {
                    slots -= cnt;
                }
                else {
                    len += cnt - slots;
                    slots = 0;
                }
            }
        }
        
        return len;
    }
};