class Solution {
public:
    void backtrack(int ind, vector<int>& v1, 
                  vector<vector<int>>& ans,
                  vector<int>& nums) {
        vector<int> nums_count (21, 0);
        for (int i = ind; i < nums.size(); i++) {
            if (nums_count[nums[i]+10] == 0) {
                nums_count[nums[i]+10] = 1;
                v1.push_back(nums[i]);
                cout << ind << " " << i << "\n";
                ans.push_back(v1);
                backtrack(i+1, v1, ans, nums);
                v1.pop_back();
            }
            
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //vector<int> nums_count (21, 0);
        
        //for (int i = 0; i < nums.size(); i++) {
        //    nums_count[nums[i] + 10]++;
        //}
        
        vector <int> v1;
        ans.push_back(v1);
        backtrack(0, v1, ans, nums);
        return ans;
    }
};