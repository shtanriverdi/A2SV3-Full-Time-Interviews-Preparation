// Question Link: https://leetcode.com/problems/symmetric-tree/

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

// Iterative BFS Implementation
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> todo;
        todo.push_back(root);
        while (!todo.empty()) {
            
            for (int i = 0, len = todo.size(); i < len / 2; i++) {
                if (todo[i] == NULL && todo[len - i - 1] || todo[i] && todo[len - i - 1] == NULL) {
                    return false;
                }
                if (todo[i] && todo[len - i - 1] && todo[i]->val != todo[len - i - 1]->val) {
                    return false;
                }
            }
            
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                todo.pop_front();
                
                if (cur) {
                    if (cur && cur->left) {
                        todo.push_back(cur->left);
                    }
                    else {
                        todo.push_back(NULL);
                    }

                    if (cur && cur->right) {
                        todo.push_back(cur->right);
                    }
                    else {
                        todo.push_back(NULL);
                    }
                }
            }
        }
        
        return true;
    }
};

// Recursive DFS Implementation
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode *l, TreeNode *r) {
        if (!l && !r) {
            return true;
        }
        if (l && !r || !l && r) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
        
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
};