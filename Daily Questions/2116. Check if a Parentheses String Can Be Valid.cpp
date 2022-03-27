// Question Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        
        // First balance the closing parantheses ')' from Left to Right
        int balance = 0;
        for (int i = 0; i < n; i++) {
            char isLocked = locked[i];
            char cur = s[i];
            if (cur == '(' || isLocked == '0') {
                balance++;
            }
            else {
                balance--;
            }
            if (balance < 0) {
                return false;
            }
        }
        
        // Then balance the opening parantheses '(' from Right To Left
        balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            char isLocked = locked[i];
            char cur = s[i];
            if (cur == ')' || isLocked == '0') {
                balance++;
            }
            else {
                balance--;
            }
            if (balance < 0) {
                return false;
            }
        }
        
        return true;
    }
};