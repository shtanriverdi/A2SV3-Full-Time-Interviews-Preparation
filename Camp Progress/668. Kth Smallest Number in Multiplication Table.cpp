// Question Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (isEnough(m, n, mid, k)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
    bool isEnough(int m, int n, int val, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(val / i, n);
        }
        
        return count >= k;
    }
};