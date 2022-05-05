# Question Link: https://leetcode.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        dsu = {}
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    key = str(i) + ',' + str(j)
                    dsu[key] = key
                    if j - 1 >= 0 and grid[i][j - 1] == '1':
                        b = str(i) + ',' + str(j - 1)
                        self.union(key, b, dsu)
                    if i - 1 >= 0 and grid[i - 1][j] == '1':
                        b = str(i - 1) + ',' + str(j)
                        self.union(key, b, dsu)
        
        num_of_islands = 0
        for key, val in dsu.items():
            if key == val:
                num_of_islands += 1
        
        return num_of_islands
    
    def find(self, cur, dsu):
        if dsu[cur] == cur:
            return cur
        return self.find(dsu[cur], dsu)
    
    def union(self, a, b, dsu):
        parent_a = self.find(a, dsu)
        parent_b = self.find(b, dsu)
        dsu[parent_a] = parent_b
