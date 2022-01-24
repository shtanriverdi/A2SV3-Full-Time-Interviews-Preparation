// Question Link: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Dummy node
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        
        // This will be the new head at the end
        ListNode *newHead = dummy;
        
        ListNode *p = head->next;
        ListNode *n = head->next->next;
        ListNode *nn = head->next->next->next;
        
        
        while (p && n) {
            n->next = p;
            p->next = nn;
            head->next = n;
            // Update pointers
            head = p;
            p = nn;
            n = p ? p->next : NULL;
            nn = n ? n->next : NULL;
        }
        
        return newHead->next;
    }
};