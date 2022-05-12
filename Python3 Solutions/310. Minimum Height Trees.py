# Question Link: https://leetcode.com/problems/minimum-height-trees/

from collections import deque

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        graph = defaultdict(set)
        edge_count = [0] * n
        
        for a, b in edges:
            graph[a].add(b)
            graph[b].add(a)
            edge_count[a] += 1
            edge_count[b] += 1
            
        leaves = deque()
        for i, count in enumerate(edge_count):
            if count == 1:
                leaves.append(i)
                
        while leaves:
            
            if len(graph) <= 2:
                break
                
            for k in range(len(leaves)):
                cur = leaves.popleft()
                parent = graph[cur].pop()
                
                graph.pop(cur)
                graph[parent].remove(cur)
                
                edge_count[parent] -= 1
                if edge_count[parent] == 1:
                    leaves.append(parent)
        
        return list(graph.keys())        