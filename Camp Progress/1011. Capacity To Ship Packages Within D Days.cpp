// Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        weights.push_back(INT_MAX);
        int l = 1, r = 25000000, m, best;
        while (l <= r) {
            m = l + (r - l) / 2;
            int d = getDaysWithCapacity(weights, m);
            if (d <= days) {
                best = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return best;
    }
    
    int getDaysWithCapacity(vector<int> &weights, long capacity) {
        long weightSum = 0;
        int days = 0, len = weights.size();
        for (int i = 0; i < len; i++) {
            // If any weight exceeds the ship's capacity
            if (i != len - 1 && weights[i] > capacity) {
                return INT_MAX;
            }
            weightSum += weights[i];
            if (weightSum > capacity) {
                weightSum = weights[i];
                days++;
            }
        }
        
        return days;
    }
};