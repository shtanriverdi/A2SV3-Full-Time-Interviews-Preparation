// Question Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == ')') {
                string temp;
                for (; !stack.empty() && stack.top() != '('; stack.pop()) {
                    temp += stack.top();
                }
                stack.pop();
                for (char c : temp) {
                    stack.push(c);
                }
            }
            else {
                stack.push(c);
            }
        }
        
        string result;
        for (; !stack.empty(); stack.pop()) {
            result += stack.top();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};