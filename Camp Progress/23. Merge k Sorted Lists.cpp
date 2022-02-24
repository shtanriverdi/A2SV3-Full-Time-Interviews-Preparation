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
        priority_queue<pair<int, ListNode*>> pq;
        for (ListNode* &list : lists) {
            if (list != NULL) {
                pq.push({ -1 * list->val, list });
            }
        }
        
        ListNode* mergedList = new ListNode(1453);
        ListNode* w = mergedList;
        while (!pq.empty()) {
            pair<int, ListNode*> cur = pq.top();
            pq.pop();
            
            w->next = new ListNode(-1 * cur.first);
            w = w->next;
            cur.second = cur.second->next;
            cur.first = cur.second ? -1 * cur.second->val : INT_MIN;
            
            if (cur.second) {
                pq.push(cur);
            }
        }
        
        return mergedList->next;
    }
};