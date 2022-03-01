// Question Link: https://leetcode.com/problems/binary-tree-tilt/

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
    int findTilt(TreeNode* root) {
        int tiltSum = helper(root)[1];
        return tiltSum;
    }
    
    vector<int> helper(TreeNode* cur) {
        if (cur == NULL) {
            return { 0, 0 };
        }
        
        vector<int> L = helper(cur->left);
        vector<int> R = helper(cur->right);
        
        int tilt = abs(L[0] - R[0]);
        int subTreeSum = L[0] + R[0] + cur->val;
        
        return { subTreeSum, tilt + L[1] + R[1] }; // { subTreeSum, tiltSum }
    }
};