// Question Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* cur, int target) {
        if (cur == NULL) {
            return NULL;
        }
        if (cur->val == target) {
            return cur;
        }
        else if (target > cur->val) {
            return searchBST(cur->right, target);
        }
        return searchBST(cur->left, target);
    }
};