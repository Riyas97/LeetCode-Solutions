class Solution {
public:
    void backtrack(int ind, vector<vector<int>>& ans, 
                  vector<int>& nums,
                  vector<int>& v1) {
        for (int i = ind; i < nums.size(); i++) {
            v1.push_back(nums[i]);
            ans.push_back(v1);
            backtrack(i+1, ans, nums, v1);
            v1.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v1;
        ans.push_back(v1);
        for (int i = 0; i < nums.size(); i++) {
            v1.push_back(nums[i]);
            ans.push_back(v1);
            backtrack(i+1, ans, nums, v1);
            v1.pop_back();
        }
        return ans;
    }
};