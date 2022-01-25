// Question Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        vector<int> nums;
        for (ListNode* i = head; i; i = i->next) {
            nums.push_back(i->val);
        }
        int maxTwinSum = INT_MIN, len = nums.size();
        for (int i = 0; i < len / 2; i++) {
            maxTwinSum = max(nums[i] + nums[len - i - 1], maxTwinSum);
        }
        return maxTwinSum;
    }
};