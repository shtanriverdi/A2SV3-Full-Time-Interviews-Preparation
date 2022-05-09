# Question Link: https://leetcode.com/problems/number-of-provinces/

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        dsu = [ _ for _ in range(n) ]
        rank = [1]*n
        
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    self.union(i, j, dsu, rank)
                    isConnected[i][j] = 0
                    isConnected[j][i] = 0
            
        provinces = set()
        for p in dsu:
            provinces.add(self.find(dsu[p], dsu))
                
        return len(provinces)

    def find(self, c, dsu):
        if dsu[c] == c:
            return c
        dsu[c] = self.find(dsu[c], dsu)
        return dsu[c]
    
    def union(self, a, b, dsu, rank):
        A = self.find(a, dsu)
        B = self.find(b, dsu)
        
        if dsu[A] == dsu[B]:
            return
        
        dsu[B] = A
        
        if rank[B] > rank[A]:
            A, B = B, A
        
        rank[A] += rank[B]
        