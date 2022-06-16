# Question Link: https://leetcode.com/problems/longest-palindromic-substring/
from collections import deque

class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        todo = deque()
        for i in range(length):
            todo.append((i, i))
            
        longest_pal_length = 1
        longest_pal_i_j = (0, 0)
        
        seen = set()
        while todo:
            i, j = todo.popleft()
            
            if i - j + 1 > longest_pal_length:
                longest_pal_length = i - j + 1
                longest_pal_i_j = (i, j)
            
            prev_i_j_len = i - j + 1
            new_right = (i + 1, j)
            if i + 1 < length and (new_right not in seen) and s[i + 1] == s[j] and prev_i_j_len == 1:
                todo.append(new_right)
                seen.add(new_right)
                
            new_left = (i, j - 1)
            if j - 1 >= 0 and (new_left not in seen) and s[j - 1] == s[i] and prev_i_j_len == 1:
                todo.append(new_left)
                seen.add(new_left)
            
            new_left_right = (i + 1, j - 1)
            if i + 1 < length and (new_left_right not in seen) and j - 1 >= 0 and s[i + 1] == s[j - 1]:
                todo.append(new_left_right)
                seen.add(new_left_right)
        
        i, j = longest_pal_i_j[0], longest_pal_i_j[1]
        return s[j:i+1]