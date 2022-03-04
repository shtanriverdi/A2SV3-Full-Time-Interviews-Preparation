// Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        unordered_map<TreeNode*, TreeNode*> nodeParentMap;
        priority_queue<pair<int, TreeNode*>> pq;
        dfs(0, root, NULL, pq, nodeParentMap);
        
        pair<int, TreeNode*> deepest = pq.top();
        pq.pop();
        
        queue<TreeNode*> todo;
        todo.push(deepest.second);
        
        for (; pq.size() > 0 && pq.top().first == deepest.first; pq.pop()) {
            todo.push(pq.top().second);
        }
        
        unordered_set<TreeNode*> parents;
        while (todo.size() != 1) {
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                todo.pop();
                TreeNode* parent = nodeParentMap[cur];
                if (parent && parents.find(parent) == parents.end()) {
                    todo.push(parent);
                    parents.insert(parent);
                }
            }
        }
        
        return todo.front();
    }
    
    void dfs(int depth, TreeNode* cur, TreeNode *parent, priority_queue<pair<int, TreeNode*>> &pq, unordered_map<TreeNode*, TreeNode*> &nodeParentMap) {
        if (!cur) {
            return;
        }
        
        depth++;
        pq.push({ depth, cur });
        nodeParentMap[cur] = parent;
        
        dfs(depth, cur->left, cur, pq, nodeParentMap);
        dfs(depth, cur->right, cur, pq, nodeParentMap);
    }
};