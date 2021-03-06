// Question Link: https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        if (len == 1) {
            return "";
        }
        
        string lexSmallestNonPalindromStr = string(len, 'z');
        for (int i = 0; i < len; i++) {
            if (len % 2 == 1 && i == len / 2) {
                continue;
            }
            char prevLetter = palindrome[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (palindrome[i] != c) {
                    palindrome[i] = c;
                    if (palindrome < lexSmallestNonPalindromStr) {
                        lexSmallestNonPalindromStr = palindrome;
                    }
                }
            }
            palindrome[i] = prevLetter;
        }
        
        return lexSmallestNonPalindromStr;
    }
};