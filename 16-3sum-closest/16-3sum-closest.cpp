class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            
            while (s < e) {
                int sum = a + nums[s] + nums[e];
                int d1 = abs(sum - target);
                if (d1 < abs(ans)) {
                    ans = sum - target;
                }
                
                
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    e -= 1; 
                } else {
                    s += 1;
                }
            }
        }
        return target + ans;
    }
};