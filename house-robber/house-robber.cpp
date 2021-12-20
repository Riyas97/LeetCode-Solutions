class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        
        if(m == 0) {
            return 0;
        }
        if (m == 1) {
            return nums[0];
        }
        int val2 = max(nums[0], nums[1]);
        if (m == 2) {
            return val2;
        }
        
        int val1 = nums[0];
        int robVal = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            robVal = max(val1 + nums[i], val2);
            val1 = val2;
            val2 = robVal;
        }
        return robVal;
    }
};