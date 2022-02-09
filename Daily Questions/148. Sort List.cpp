// Question Link: https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        vector<int> counts(200001);
        for (ListNode* w = head; w; w = w->next) {
            counts[w->val + 100001]++;
        }
        
        ListNode* newList = new ListNode(1453);
        ListNode* w = newList;
        for (int i = 0; i < counts.size(); i++) {
            while (counts[i] > 0) {
                w->next = new ListNode(i - 100001);
                w = w->next;
                counts[i]--;
            }
        }
        return newList->next;
    }
};