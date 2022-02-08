// Question Link: https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) {
            return true;
        }
        
        if (n <= 0 || n % 4 != 0) {
            return false;
        }
        
        double div = n / 4 * 1.0;
        while (div > 0.0) {
            if (div == 1.0) {
                return true;
            }
            div = (div / 4) * 1.0;
        }
        
        return false;
    }
};