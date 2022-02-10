class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> us;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i != 0 && sum % k == 0) {
                return true;
            }
            int remain = sum % k;
            if (us.find(remain) != us.end()) {
                int ind = us[remain];
                if (ind != i - 1) {
                    return true;
                }
            } else {
                us[remain] = i;
            }
        } 
        
        return false;
    }
};