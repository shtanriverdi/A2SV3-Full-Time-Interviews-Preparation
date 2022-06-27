# Question Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

# 1 Liner
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))

# Decent Solution
class Solution:
    def minPartitions(self, n: str) -> int:
        
        int_list = [ int(i) for i in n ]
        
        return max(int_list)