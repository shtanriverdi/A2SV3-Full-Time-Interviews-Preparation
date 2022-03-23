// Question Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> result;

        deque<TreeNode*> todo;
        todo.push_back(root);
        
        while (!todo.empty()) {
            int levelMax = INT_MIN;
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                levelMax = max(levelMax, cur->val);                
                todo.pop_front();
                if (cur->left) {
                    todo.push_back(cur->left);
                }
                if (cur->right) {
                    todo.push_back(cur->right);
                }
            }
            result.push_back(levelMax);
        }
        
        return result;
    }
};