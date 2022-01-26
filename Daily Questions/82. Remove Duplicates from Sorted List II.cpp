// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        set<int> valSet;
        unordered_set<int> duplicateSet;
        for (ListNode* w = head; w; w = w->next) {
            if (valSet.find(w->val) != valSet.end()) {
                duplicateSet.insert(w->val);
            }
            else {
                valSet.insert(w->val);
            }
        }
        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *w = newHead;
        for (auto &it : valSet) {
            if (duplicateSet.find(it) == duplicateSet.end()) {
                w->next = new ListNode(it);
                w = w->next;
            }
        }
        return newHead->next;
    }
};