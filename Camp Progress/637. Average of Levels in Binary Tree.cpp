// Question Link: https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        deque<TreeNode*> todo;
        todo.push_back(root);
        while (!todo.empty()) {
            
            double levelSum = 0.0;
            for (TreeNode* &node : todo) {
                levelSum += node->val * 1.0;
            }
            result.push_back(levelSum / todo.size());
            
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                todo.pop_front();
                if (cur->left) {
                    todo.push_back(cur->left);
                }
                if (cur->right) {
                    todo.push_back(cur->right);
                }
            }
        }
        
        return result;
    }
};