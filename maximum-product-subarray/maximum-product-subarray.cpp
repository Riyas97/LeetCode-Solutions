class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int g_max = nums[0];
        int g_min = nums[0];
        int c_product = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            
            int l_max = max({c_product * nums[i], nums[i], 
                             g_min * nums[i]});
            g_min = min({c_product * nums[i], nums[i], 
                             g_min * nums[i]});
            
            g_max = max(g_max, l_max);
            c_product = l_max;
        }
        return g_max;
    }
};