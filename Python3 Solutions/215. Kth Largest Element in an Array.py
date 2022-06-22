# Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        counts = [0]*20001
        for num in nums:
            counts[num + 10000] += 1
        
        kth = 0
        for index in reversed(range(20001)):
            kth += counts[index]
            if kth >= k:
                return index - 10000
                