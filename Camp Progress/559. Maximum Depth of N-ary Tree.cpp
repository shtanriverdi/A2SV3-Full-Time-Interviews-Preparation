// Question Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* cur) {
        if (cur == NULL) {
            return 0;
        }
        
        int result = 1;
        for (Node* child : cur->children) {
            result = max(1 + maxDepth(child), result);
        }
        
        return result;
    }
};