// Question Link: https://www.hackerrank.com/contests/a2sv-3-contest-4/challenges/tree-height-of-a-binary-tree/

int depth(Node* cur) {
    if (cur == NULL) {
        return 0;
    }
    return max(
        ((cur->left) ? 1 : 0) + depth(cur->left),
        ((cur->right) ? 1 : 0) + depth(cur->right)
    );
}

int height(Node* root) {
    return depth(root);
}