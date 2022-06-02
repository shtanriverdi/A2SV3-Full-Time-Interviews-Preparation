# Question Link: https://leetcode.com/problems/maximum-product-subarray/

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        
        left_prefix_prod = [0] * n
        left_prefix_prod[0] = nums[0]
        
        right_prefix_prod = [0] * n
        right_prefix_prod[-1] = nums[-1]
        
        for i in range(1, n):
            left_prefix_prod[i] = nums[i] * left_prefix_prod[i - 1]
            if nums[i - 1] == 0:
                left_prefix_prod[i] = nums[i]
            
        for i in reversed(range(n - 1)):
            right_prefix_prod[i] = nums[i] * right_prefix_prod[i + 1]
            if nums[i + 1] == 0:
                right_prefix_prod[i] = nums[i]
            
        max_product_sum = float("-inf")
        for i in range(n):
            max_product_sum = max(left_prefix_prod[i], right_prefix_prod[i], max_product_sum)
        
        return max_product_sum