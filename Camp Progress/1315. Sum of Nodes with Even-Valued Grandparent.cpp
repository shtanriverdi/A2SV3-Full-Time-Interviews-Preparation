// Question Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution {
public:
    int sumEvenGrandparent(TreeNode* cur) {
        if (cur == NULL) {
            return 0;
        }
        
        int curParentSum = 0;
        if (cur->val % 2 == 0) {
            if (cur->left) {
                curParentSum += cur->left->left ? cur->left->left->val : 0;
                curParentSum += cur->left->right ? cur->left->right->val : 0;
            }

            if (cur->right) {
                curParentSum += cur->right->left ? cur->right->left->val : 0;
                curParentSum += cur->right->right ? cur->right->right->val : 0;
            }
        }
        
        int LParentSum = sumEvenGrandparent(cur->left);
        int RParentSum = sumEvenGrandparent(cur->right);
        
        return LParentSum + RParentSum + curParentSum;
    }
};