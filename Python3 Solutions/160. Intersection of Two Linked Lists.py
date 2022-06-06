# Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Constant Space Solution
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        walk_a = headA
        len_a = 0
        last_node_a = None
        while walk_a:
            len_a += 1
            if walk_a.next == None:
                last_node_a = walk_a
            walk_a = walk_a.next
            
        walk_b = headB
        last_node_b = None
        len_b = 0
        while walk_b:
            len_b += 1
            if walk_b.next == None:
                last_node_b = walk_b
            walk_b = walk_b.next
            
        if last_node_b != last_node_a:
            return None
        
        longer_list = headA
        shorter_list = headB
        if len_b > len_a:
            longer_list = headB
            shorter_list = headA
            len_a, len_b = len_b, len_a
        
        while len_a > len_b:
            len_a -= 1
            longer_list = longer_list.next
        
        while longer_list and shorter_list and longer_list != shorter_list:
            longer_list = longer_list.next
            shorter_list = shorter_list.next
            
        return shorter_list

    
# Linear Space Solution
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
