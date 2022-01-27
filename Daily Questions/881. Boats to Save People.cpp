// Question Link: https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, len = people.size(), r = len - 1, result = 0;
        while (l < r) {
            if (people[r] + people[l] <= limit) {
                l++;
            }
            result++;
            r--;
        }
        return result + (l == r);
    }
};
