# Question Link: https://leetcode.com/problems/reverse-bits/

class Solution:
    def reverseBits(self, n: int) -> int:
        left_pointer = 2**31
        reverse = 0
        
        while n > 0:
            reverse += left_pointer * (n & 1)
            left_pointer >>= 1
            n >>= 1
        
        return reverse