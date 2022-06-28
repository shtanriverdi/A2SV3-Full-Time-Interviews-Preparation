# Question Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
from collections import Counter, defaultdict

class Solution:
    def minDeletions(self, s: str) -> int:
        counts = Counter(s)
        
        count_map = defaultdict(int)
        for num, count in counts.items():
            count_map[count] += 1
            
        counting_list = [0] * 100001
        for num, count in count_map.items():
            counting_list[num] = count
        
        answer = [0]
        for i in reversed(range(1, 100001)):
            if counting_list[i] > 1:
                answer[0] += counting_list[i] - 1
                counting_list[i - 1] += counting_list[i] - 1
            
        return answer[0]