class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> v1;
        vector <int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                v1.push_back(nums[i] * nums[i]);
            } else {
                int b = nums[i] * nums[i];
        
                while (v1.size() > 0 && v1[v1.size() - 1] < b) {
                    ans.push_back(v1[v1.size() - 1]);
                    v1.pop_back();
                }
                ans.push_back(b);    
            }
        }
        if (v1.size() > 0) {
            for (int i = v1.size() - 1; i >= 0; i--) {
                ans.push_back(v1[i]);
            }
        }
        return ans;
    }
};