// Question Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1, m, count, best;
        while (l <= r) {
            m = l + (r - l) / 2;
            count = getCountLessThanN(nums, m);
            cout << "cur: " << m << " cnt: " << count << endl;
            if (count > m - 1) {
                best = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return best - 1;
    }
    
    int getCountLessThanN(vector<int>& nums, int n) {
        int count = 0;
        for (int &num : nums) {
            if (num < n) {
                count++;
            }
        }
        
        return count;
    }
};