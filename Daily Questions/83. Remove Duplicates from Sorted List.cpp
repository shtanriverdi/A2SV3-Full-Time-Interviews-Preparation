// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* walk = head;
        while (walk && walk->next) {
            if (walk->val == walk->next->val) {
                walk->next = walk->next->next;
            }
            else {
                walk = walk->next;
            }
        }
        return head;
    }
};