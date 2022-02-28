// Question Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1000000, m, res, bestDivisor;
        while (l <= r) {
            m = l + (r - l) / 2;
            res = getResult(nums, m);
            if (res <= threshold) {
                bestDivisor = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return bestDivisor;
    }
    
    int getResult(vector<int> &nums, int d) {
        int result = 0;
        for (int &n : nums) {
            if (n <= d) {
                result += 1;
            }
            if (n > d) {
                result += ceil(n / d) + ((d != 1) && (n % d != 0) ? 1 : 0);
            }
        }
        
        return result;
    }
};