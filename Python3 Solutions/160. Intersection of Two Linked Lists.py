# Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        seen = set()
        
        walk_a = headA
        while walk_a:
            seen.add(walk_a)
            walk_a = walk_a.next
        
        walk_b = headB
        while walk_b:
            if walk_b in seen:
                return walk_b
            walk_b = walk_b.next
            
        return None