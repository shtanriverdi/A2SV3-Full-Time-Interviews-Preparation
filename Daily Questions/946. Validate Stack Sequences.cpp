// Question Link: https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size(), pushIdx = 0, popIdx = 0;
        stack<int> stack;
        while (pushIdx < len) {
            stack.push(pushed[pushIdx++]);
            if (stack.empty()) {
                return false;
            }
            while (!stack.empty() && stack.top() == popped[popIdx]) {
                stack.pop();
                popIdx++;
            }
        }
        
        return stack.empty();
    }
};