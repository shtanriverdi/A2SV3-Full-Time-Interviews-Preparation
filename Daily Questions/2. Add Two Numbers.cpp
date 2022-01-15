// Question Link: https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (l1 || l2) {
            sum = (l1 ? (l1->val) : 0) 
                + (l2 ? (l2->val) : 0) 
                + carry;
            
            int digit = sum % 10;
            
            curr->next = new ListNode(digit);
            curr = curr->next;
            carry = sum / 10;
            l1 = (l1 && l1->next) ? l1->next : NULL;
            l2 = (l2 && l2->next) ? l2->next : NULL;
        }
        
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        
        return head->next;
    }
};