# Question Link: https://leetcode.com/problems/course-schedule-ii

# DFS Solution
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for x in range(numCourses)]
        for dest, src in prerequisites:
            graph[src].append(dest)
        
        index = [numCourses - 1]
        result = [0] * numCourses
        seen = [False] * numCourses
        
        for cur in range(numCourses):
            cycle = [False] * numCourses
            if seen[cur] == False:
                hasCycle = self.dfs(cur, graph, seen, cycle, result, index)
                if hasCycle:
                    return []
                
        return result
    
    def dfs(self, cur, graph, seen, cycle, result, index) -> bool:
        seen[cur] = True
        cycle[cur] = True
        
        for neigh in graph[cur]:
            if seen[neigh] == False:
                hasCycle = self.dfs(neigh, graph, seen, cycle, result, index)
                if hasCycle:
                    return True
                
            elif cycle[neigh]:
                return True
            
        result[index[0]] = cur
        index[0] -= 1
        cycle[cur] = False
        return False


# BFS Solution Kahn's Algorithm
from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for x in range(numCourses)]
        indegrees = [0] * numCourses
        for dest, src in prerequisites:
            graph[src].append(dest)
            indegrees[dest] += 1
            
        todo = deque()
        for i in range(numCourses):
            if indegrees[i] == 0:
                todo.append(i)
                
        result = []
        totalCoursesProcessed = 0
        while todo:
            cur = todo.pop()
            result.append(cur)
            totalCoursesProcessed += 1
            for neigh in graph[cur]:
                indegrees[neigh] -= 1
                if indegrees[neigh] == 0:
                    todo.append(neigh)
        
        if totalCoursesProcessed != numCourses:
            result = []
        
        return result