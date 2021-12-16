class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (nums[i] < 0) {
                a *= -1;
            }
            
            if (nums[a - 1] > 0) {
                nums[a - 1] *= -1;
            } 
        }
        
        vector <int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};