// Question Link: https://leetcode.com/problems/next-greater-node-in-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> numStack;
        for (; head; head = head->next) {
            numStack.push(head->val);
        }
        
        int len = numStack.size(), i = len - 1;
        vector<int> result(len, 0);
        stack<int> greaterStack;
        for (; !numStack.empty(); numStack.pop()) {
            while (!greaterStack.empty() && greaterStack.top() <= numStack.top()) {
                greaterStack.pop();
            }
            result[i--] = !greaterStack.empty() ? greaterStack.top() : 0;
            greaterStack.push(numStack.top());
        }
        
        return result;
    }
};