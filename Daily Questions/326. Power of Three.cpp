// Question Link: https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) {
            return true;
        }
        
        if (n <= 0 || n % 3 != 0) {
            return false;
        }
        
        // Divisible by three
        double div = n / 3 * 1.0;
        while (div > 0.0) {
            if (div == 1.0) {
                return true;
            }
            div = (div / 3) * 1.0;
        }
        
        return false;
    }
};