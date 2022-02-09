// Question Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        vector<int> counts(10001, 0);
        for (int &pile : piles) {
            counts[pile]++;
        }
        
        vector<int> sorted;
        for (int i = 0; i < 10001; i++) {
            while (counts[i] > 0) {
                sorted.push_back(i);
                counts[i]--;
            }
        }
        
        int len = sorted.size(), maxCoins = 0;
        int leftEndIdx = len / 3;
        int secondMaxIdx = len - 2;
        for (; secondMaxIdx >= leftEndIdx; secondMaxIdx -= 2) {
            maxCoins += sorted[secondMaxIdx];
        } 
        
        return maxCoins;
    }
};