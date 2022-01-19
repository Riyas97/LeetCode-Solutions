class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        int ans = 1;
        int bk = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (dp[i]) {
                continue;
            }
            
            dp[i] = true;
            int s = nums[i];
            int count = 1;
            unordered_set <int> ind;
            ind.insert(i);
            
            while (true) {
                if (s >= nums.size()) {
                    //dp[i] = count;
                    break;
                }
                if (ind.find(s) != ind.end()) {
                    //dp[i] = count;
                    break;
                }
                count++;
                dp[s] = true;
                s = nums[s];
            }
            
            ans = max(ans, count);
        }
        
        
        return ans;
    }
};