// Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* slow = head;
        ListNode* fast = head;
        int slowIdx = 1, fastIdx = 1;
        while (fast && fast->next) {
            slowIdx += 1;
            fastIdx += 2;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int len = (fast == NULL) ? (fastIdx - 1) : fastIdx;
        if (len == 1) {
            return NULL;
        }
        
        int midIdx = len - slowIdx + 1;
        
        ListNode* pointerToUse = (n < midIdx) ? slow : head;
        int pointerIdx = (n < midIdx) ? midIdx : len;
        // If we remove head
        if (n == pointerIdx) {
            head = head->next;
            return head;
        }

        while (pointerIdx != n + 1) {
            pointerIdx--;
            pointerToUse = (pointerToUse) ? pointerToUse->next : NULL;
        }
        pointerToUse->next = pointerToUse->next->next;
        
        return head;
    }
};