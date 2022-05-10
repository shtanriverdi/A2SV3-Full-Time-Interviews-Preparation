# Question Link: https://leetcode.com/problems/max-area-of-island/

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxIslands = [0]
        
        dirs = [0, 1, 0, -1, 0]
        dsu = {}
        rank = [[1]*n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    maxIslands[0] = max(maxIslands[0], grid[i][j])
                    for d in range(1, 5):
                        ni, nj = dirs[d] + i, dirs[d - 1] + j
                        if self.is_valid(ni, nj, m, n, grid):
                            a = str(i)+'.'+str(j)
                            b = str(ni)+'.'+str(nj)
                            self.union(a, b, dsu, rank, maxIslands)
                        
        return maxIslands[0]
        
    def union(self, a, b, dsu, rank, maxIslands):
        dsu[a] = dsu[a] if a in dsu else a
        dsu[b] = dsu[b] if b in dsu else b
        
        A = self.find(a, dsu)
        B = self.find(b, dsu)
        
        if A == B:
            return
        
        dsu[B] = A
        
        Ai, Aj = list(map(int, A.split('.')))
        Bi, Bj = list(map(int, B.split('.')))
        
        rank[Ai][Aj] = rank[Ai][Aj] + rank[Bi][Bj]
        
        maxIslands[0] = max(maxIslands[0], rank[Ai][Aj])
        
    def find(self, c, dsu):
        if dsu[c] == c:
            return c
        dsu[c] = self.find(dsu[c], dsu)
        return dsu[c]
        
    def is_valid(self, i, j, m, n, grid):
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
            return False
        return True
        
        