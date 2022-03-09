// Question Link: https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int minBoatsUsed = 0, weightSum = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            weightSum = people[l] + people[r];
            minBoatsUsed++;
            if (weightSum <= limit) {
                l++;
                r--;
            }
            else {
                r--;
            }
        }
        
        return minBoatsUsed;
    }
};