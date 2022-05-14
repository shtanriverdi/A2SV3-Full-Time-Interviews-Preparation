# Question Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

from collections import deque

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        indegrees = [0] * n
        
        for a, b in edges:
            graph[a].append(b)
            indegrees[b] += 1
            
        todo = deque()
        for node, degree in enumerate(indegrees):
            if degree == 0:
                todo.append(node)
        
        result = [[] for _ in range(n)]
        ancestors = defaultdict(set)
        while todo:
            cur = todo.popleft()
            for neigh in graph[cur]:
                
                ancestors[neigh].add(cur)
                for ancestor in ancestors[cur]:
                    ancestors[neigh].add(ancestor)
                    
                indegrees[neigh] -= 1
                if indegrees[neigh] == 0:
                    todo.append(neigh)
        
        for key in ancestors:
            for ancestor in ancestors[key]:
                result[key].append(ancestor)
                result[key].sort()
        
        return result