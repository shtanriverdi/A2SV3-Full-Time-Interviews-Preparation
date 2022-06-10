// Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, answer = 0;
        unordered_map<char, int> countMap;
        for (int right = 0; right < s.size(); right++) {
            countMap[s[right]]++;
            while (countMap[s[right]] > 1) {
                countMap[s[left]]--;
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        
        return answer;
    }
};