class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set <int> u;
        for (int i = 0; i < nums.size(); i++) {
            u.insert(nums[i]);
        }
        
        for (auto it = u.begin(); it != u.end(); it++) {
            int n = *it;
            // find the first number in series
            if (u.find(n-1) == u.end()) {
                int ans1 = 1;
                while (u.find(n+1) != u.end()) {
                    ans1++;
                    n++;
                }
                ans = max(ans, ans1);
            } else {
                continue;
            }
        }
        return ans;
    }
};