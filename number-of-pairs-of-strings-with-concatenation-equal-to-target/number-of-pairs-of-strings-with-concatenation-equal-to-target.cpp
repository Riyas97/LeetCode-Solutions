class Solution {
public:
    
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int t = target.size();
        unordered_map <string, int> u;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = t - nums[i].size();
            if (num <= 0) {
                continue;
            }
            if (num == 0 && nums[i] == target) {
                ans += 1;
                continue;
            }
            
            bool va1, va2 = false;
            string f1 = target.substr(0, nums[i].size());
            if (f1 == nums[i]) {
                // i is nums[i]
                // find j
                va1 = true;
                string f2 = target.substr(
                    nums[i].size(), t - nums[i].size());
                if (u.find(f2) != u.end()) {
                    int b = u[f2];
                    ans += b;
                }
            }
            
            string f3 = target.substr(
                t - nums[i].size(), nums[i].size());
            if (f3 == nums[i]) {
                // i is nums[i]
                // find j
                va2 = true;
                string f4 = target.substr(
                    0, t - nums[i].size());
                if (u.find(f4) != u.end()) {
                    int b = u[f4];
                    cout << f4 << " " << f3 << " " << b << "\n";
                    ans += b;
                }
            }
            
            if (u.find(nums[i]) == u.end()) {
                    u[nums[i]] = 1;
            } else {
                u[nums[i]] += 1;
            }
        }
        return ans;
    
    }
};