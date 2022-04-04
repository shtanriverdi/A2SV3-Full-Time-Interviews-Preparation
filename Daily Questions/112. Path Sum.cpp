// Question Link: https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* cur, int targetSum) {
        if (cur == NULL) {
            return false;
        }
        
        targetSum -= cur->val;
        if (!cur->left && !cur->right) {
            return targetSum == 0;
        }
        
        return hasPathSum(cur->left, targetSum) || hasPathSum(cur->right, targetSum);
    }
};
