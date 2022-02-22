class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> v1(nums.size(), 0);
        vector<int> v2(nums.size(), 0);
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            v1[i] = sum;
            sum += nums[i];
        }
        
        sum = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            v2[i] = sum;
            sum += nums[i];
        }
        
        //for (int i = 0; i < nums.size(); i++) {
            //cout << v1[i] << " " << v2[i] << "\n";
        //}
        
        vector<int> ans(nums.size(), 0);
        int size = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans[i] = v2[i] - (nums[i] * size); 
            } else if (i == nums.size() - 1) {
                ans[i] = (nums[i] * size) - v1[i];
            } else {
                ans[i] += v2[i] - (nums[i] * (nums.size()-1-i));
                //cout << (nums.size()-1-i) << " " << ans[i];
                ans[i] += (nums[i] * i) - v1[i];
            }
        }
        
        return ans;
        
    }
};