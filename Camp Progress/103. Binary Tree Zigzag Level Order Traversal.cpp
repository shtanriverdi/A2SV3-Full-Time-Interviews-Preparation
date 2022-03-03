// Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        deque<TreeNode*> todo;
        todo.push_back(root);
        vector<vector<int>> result = {{ root->val }};
        bool zigzag = false;
        
        while (!todo.empty()) {            
            
            vector<int> level;
            
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                todo.pop_front();
                if (cur->left) {
                    todo.push_back(cur->left);
                    level.push_back(cur->left->val);
                }
                if (cur->right) {
                    todo.push_back(cur->right);
                    level.push_back(cur->right->val);
                }
            }
            
            if (level.size() > 0) {
                if (zigzag) {
                    result.push_back(level);
                    zigzag = false;
                }
                else {
                    reverse(begin(level), end(level));
                    result.push_back(level);
                    zigzag = true;
                }
            }
        }
        
        return result;
    }
};