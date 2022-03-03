// Question Link: https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root) {
        vector<int> brokenList;
        unordered_map<int, TreeNode*> valueNodeMap;
        inOrder(root, brokenList, valueNodeMap);
        
        vector<int> sorted = brokenList;
        sort(begin(sorted), end(sorted));
        
        for (int i = 1; i < brokenList.size(); i++) {
            if (brokenList[i] != sorted[i]) {
                valueNodeMap[brokenList[i]]->val = sorted[i];
                valueNodeMap[sorted[i]]->val = brokenList[i];
                return;
            }
        }
    }
    
    void inOrder(TreeNode* cur, vector<int> &brokenList, unordered_map<int, TreeNode*> &valueNodeMap) {
        if (!cur) {
            return;
        }
        inOrder(cur->left, brokenList, valueNodeMap);
        brokenList.push_back(cur->val);
        valueNodeMap[cur->val] = cur;
        inOrder(cur->right, brokenList, valueNodeMap);
    }
};