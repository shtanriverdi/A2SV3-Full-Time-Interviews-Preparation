# Question Link: https://leetcode.com/problems/find-eventual-safe-states/

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        colors = [0] * n
        
        result = []
        for i in range(n):
            safe = self.dfs(i, graph, colors)
            if safe:
                result.append(i)
                
        return result
    
    # 0: White, 1: Gray(Unsafe), 2: Black(Safe)
    def dfs(self, cur, graph, colors) -> bool:
        if colors[cur] > 0:
            return colors[cur] == 2
        
        colors[cur] = 1
        
        for neigh in graph[cur]:
            safe = self.dfs(neigh, graph, colors)
            if not safe:
                return False
            
        colors[cur] = 2
        return True