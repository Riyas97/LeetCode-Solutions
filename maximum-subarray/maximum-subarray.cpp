class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cout << a + nums[i] << " " << nums[i] << "\n";
            a = max(nums[i], a+nums[i]);
            //cout << a << "\n";
            
            ans = max(a, ans);
        }
        return ans;
    }
};
