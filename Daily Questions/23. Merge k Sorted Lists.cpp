// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> counts(20001, 0);
        for (ListNode* &list : lists) {
            for (ListNode* w = list; w != NULL; w = w->next) {
                if (w->val < 0) {
                    counts[(-1 * (w->val)) + 10000]++;
                }
                else {
                    counts[w->val]++;
                }
            }
        }
        
        ListNode* mergedList = new ListNode(1453);
        ListNode* walk = mergedList;
        for (int i = 20000; i >= 10001; i--) {
            for (; counts[i] > 0; counts[i]--) {
                walk->next = new ListNode((i - 10000) * -1);
                walk = walk->next;
            }
        }
        for (int i = 0; i < 10001; i++) {
            for (; counts[i] > 0; counts[i]--) {
                walk->next = new ListNode(i);
                walk = walk->next;
            }
        }
        
        return mergedList->next;
    }
};