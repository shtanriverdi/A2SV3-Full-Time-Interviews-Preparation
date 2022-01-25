// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/find-the-merge-point-of-two-joined-linked-lists

/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* walk = llist;
    while (walk && walk->next) {
        if (walk->data == walk->next->data) {
            walk->next = walk->next->next;
        }
        else {
            walk = walk->next;
        }
    }
    return llist;
}
