// Question Link: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(INT_MAX); // Dummy Node
        ListNode* tail = head;
        while (list1 || list2) {
            int val1 = (list1) ? list1->val : INT_MAX;
            int val2 = (list2) ? list2->val : INT_MAX;
            if (val1 < val2) {
                appendToList(tail, val1);
                list1 = list1->next;
            }
            else {
                appendToList(tail, val2);
                list2 = list2->next;
            }
        }
        return head->next;
    }
    
    void appendToList(ListNode* &tail, int &val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
};