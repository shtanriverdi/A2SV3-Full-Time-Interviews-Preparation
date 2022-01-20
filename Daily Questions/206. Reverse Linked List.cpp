// Question Link: https://leetcode.com/problems/reverse-linked-list/

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

// Iterative Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> valStack;
        for (; head; head = head->next) {
            valStack.push(head->val);
        }
        
        ListNode* reversedHead = new ListNode(-1);
        ListNode* walk = reversedHead;
        for (; !valStack.empty(); valStack.pop(), walk = walk->next) {
            walk->next = new ListNode(valStack.top());
        }
        
        return reversedHead->next;
    }
};

// Recursive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* walk = newHead;
        helper(head, walk);
        return newHead->next;
    }
    
    void helper(ListNode *cur, ListNode* &walk) {
        if (cur == NULL) {
            return;
        }
        helper(cur->next, walk);
        walk->next = new ListNode(cur->val);
        walk = walk->next;
    }
};
