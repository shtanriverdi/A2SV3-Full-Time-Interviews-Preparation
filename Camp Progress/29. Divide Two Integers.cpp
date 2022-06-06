// Question Link: https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isANegative = dividend < 0;
        bool isBNegative = divisor < 0;
        bool isResultNegative = (isANegative && !isBNegative) || (!isANegative && isBNegative);

        long l_dividend = dividend;
        long l_divisor = divisor;
        
        l_dividend *= isANegative ? -1 : 1;
        l_divisor *= isBNegative ? -1 : 1;
        
        long quotientAnswer = 0;
        helper(l_dividend, l_divisor, quotientAnswer);
        
        quotientAnswer = isResultNegative ? (-quotientAnswer) : quotientAnswer;
        
        if (quotientAnswer > INT_MAX) {
            return INT_MAX;
        }
        else if (quotientAnswer < INT_MIN) {
            return INT_MIN;
        }
        
        return quotientAnswer;
    }
    
    void helper(long A, long B, long &C) {
        if (B > A) {
            return;
        }
        
        long curB = B;
        int step = 0;
        while ((curB << 1) < A) {
            curB = curB << 1;
            step++;
        }
        
        C += pow(2, step);
        
        long remainingA = A - curB;
        
        helper(remainingA, B, C);
    }
};