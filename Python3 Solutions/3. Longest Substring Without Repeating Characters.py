# Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        letter_counts_map = defaultdict(int)
        left, right, length, longest_length_found = 0, 0, len(s), 0
        
        for right in range(length):
            letter_counts_map[s[right]] += 1
            while letter_counts_map[s[right]] > 1:
                letter_counts_map[s[left]] -= 1
                left += 1
                
            longest_length_found = max(longest_length_found, right - left + 1)
            
        return longest_length_found
