# Question Link: https://leetcode.com/problems/course-schedule

"""
    We need to detect if given graph is DAG (Directed Acyclic Graph)
    To detect that, we need to check if graph has any cycle
"""
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