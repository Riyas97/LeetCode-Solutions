class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> v1 (nums.size(), 1);
        vector <int> v2 (nums.size(), 1);
        
        int pro = 1;
        for (int i = 0; i < nums.size(); i++) {
            pro *= nums[i];
            v1[i] = pro;
        }
        pro = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            pro *= nums[i];
            v2[i] = pro;
        }
        vector <int> ans;
        ans.push_back(v2[1]);
        
        for (int i = 1; i < nums.size() - 1; i++) {
            ans.push_back(v2[i+1] * v1[i-1]);
        }
        ans.push_back(v1[nums.size() -2]);
        return ans;
    }
};