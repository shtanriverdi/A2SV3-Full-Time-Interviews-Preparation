// Question Link: https://leetcode.com/problems/palindrome-linked-list/

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

// O(N) Time O(N) Memory
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        helper(head, nums);
        int len = nums.size();
        for (int i = 0; i < len / 2; i++) {
            if (nums[i] != nums[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    void helper(ListNode* cur, vector<int> &nums) {
        if (cur == NULL) {
            return;
        }
        nums.push_back(cur->val);
        helper(cur->next, nums);
    }
};

// O(N) Time O(N/2) Memory
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *walk = head;
        stack<int> valStack;
        while (walk != slow) {
            valStack.push(walk->val);
            walk = walk->next;
        }
        
        if (fast && fast->next == NULL) {
            slow = slow->next;
        }
        
        while(!valStack.empty() && slow) {
            if (valStack.top() != slow->val) {
                return false;
            }
            valStack.pop();
            slow = slow->next;
        }
        
        return true;
    }
};