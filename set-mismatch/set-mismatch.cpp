class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            
            if (nums[i] < 0) {
                a *= -1;
            }
            
            if (nums[a - 1] < 0) {
                ans.push_back(a);
            } else {
                nums[a - 1] *= -1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};