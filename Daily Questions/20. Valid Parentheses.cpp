// Question Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parPairMap = {
            { '(', ')' },
            { '[', ']' },
            { '{', '}' }
        };
        stack<char> stack;
        for (char c : s) {
            if (parPairMap.find(c) != parPairMap.end()) {
                stack.push(c);
            }
            else {
                if (stack.empty() || c != parPairMap[stack.top()]) {
                    return false;
                }
                stack.pop();
            }
        }
        
        return stack.empty();
    }
};