# Question Link: https://leetcode.com/problems/triangle/
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        rows = len(triangle)
        for i in reversed(range(rows - 1)):
            cols = len(triangle[i])
            for j in range(cols):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])            
            
        return triangle[0][0]
