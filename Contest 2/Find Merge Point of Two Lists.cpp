// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/find-the-merge-point-of-two-joined-linked-lists/

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    unordered_set<SinglyLinkedListNode*> nodeSet;
    SinglyLinkedListNode* walk1 = head1;
    for (; walk1; walk1 = walk1->next) {
        nodeSet.insert(walk1);
    }
    
    SinglyLinkedListNode* walk2 = head2;
    for (; walk2; walk2 = walk2->next) {
        if (nodeSet.find(walk2) != nodeSet.end()) {
            return walk2->data;
        }
    }
    
    return 0;
}