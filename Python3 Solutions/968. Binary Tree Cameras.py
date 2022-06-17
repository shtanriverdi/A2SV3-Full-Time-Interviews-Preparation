# Question Link: https://leetcode.com/problems/longest-palindromic-substring/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        camera_count = [0]
        info = self.dfs(root, camera_count)
        return camera_count[0] + 1 if info == 2 else camera_count[0]

    # 0 -> There is a camera
    # 1 -> This node is monitoring
    # 2 -> This node has no Camera, and definitely needs monitoring
    def dfs(self, cur, camera_count):
        if cur == None:
            return -1
        
        left_info = self.dfs(cur.left, camera_count)
        right_info = self.dfs(cur.right, camera_count)

        if left_info == -1 and right_info == -1:
            return 2
        
        if left_info == 2 or right_info == 2:
            camera_count[0] += 1
            return 0

        if (left_info == 1 and right_info == -1) or (left_info == -1 and right_info == 1):
            return 2
        
        if left_info == 1 and right_info == 1:
            return 2
            
        return 1
        