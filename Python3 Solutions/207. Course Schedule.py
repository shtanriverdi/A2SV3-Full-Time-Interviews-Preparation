# Question Link: https://leetcode.com/problems/course-schedule

"""
    We need to detect if given graph is DAG (Directed Acyclic Graph)
    To detect that, we need to check if graph has any cycle
"""

# BFS Solution
from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        indegrees = [0] * numCourses
        for dest, src in prerequisites:
            graph[src].append(dest)
            indegrees[dest] += 1
        
        todo = deque()
        for i in range(numCourses):
            if indegrees[i] == 0:
                todo.append(i)
                
        nodesProcesses = 0
        while todo:
            cur = todo.pop()
            nodesProcesses += 1
            for neighbor in graph[cur]:
                indegrees[neighbor] -= 1
                if indegrees[neighbor] == 0:
                    todo.append(neighbor)
                
        return nodesProcesses == numCourses

    
# DFS Solution
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        dag = [[] for x in range(numCourses)]
        for dest, source in prerequisites:
            dag[dest].append(source)
            
        seen = [False] * numCourses
        cycleSeen = [False] * numCourses
            
        for i in range(0, numCourses):
            if seen[i] == False:
                hasCycle = self.dfs(i, dag, seen, cycleSeen)
                if hasCycle:
                    return False
                
        return True
    
    def dfs(self, cur, dag, seen, cycleSeen) -> bool:
        seen[cur] = True
        cycleSeen[cur] = True
        
        for neigh in dag[cur]:
            if seen[neigh] == False:
                hasCycle = self.dfs(neigh, dag, seen, cycleSeen)
                if hasCycle:
                    return True
                
            elif cycleSeen[neigh] == True:
                return True
        
        cycleSeen[cur] = False
        return False
