class Solution {
public:
    
    
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> um;
        int sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < x) {
                um[sum] = i+1;
            } else if (sum == x) {
                ans = min(ans, i+1);
            } else {
                break;
            }
        }
        if (sum < x) {
            return -1;
        }
        sum = 0;
        int ind = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            ind++; 
            if (sum < x) {
                if (um.find(x - sum) != um.end()) {
                    //cout << ind << " " << x-sum;
                    ans = min(ans, ind+um[x-sum]);
                }
            } else if (sum == x) {
                ans = min(ans, ind);
            } else {
                break;
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};