// Question Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    int distributeCoins(TreeNode* root) {
        return dfs(root)[1];
    }
    
    vector<int> dfs(TreeNode* cur) {
        if (!cur) {
            return { 0, 0 };
        }
        
        vector<int> l = dfs(cur->left);
        vector<int> r = dfs(cur->right);
        
        int need = (cur->val - 1) + l[0] + r[0];
        int cost = abs(l[1]) + abs(r[1]) + abs(need);
        
        return { need, cost };
    }
};