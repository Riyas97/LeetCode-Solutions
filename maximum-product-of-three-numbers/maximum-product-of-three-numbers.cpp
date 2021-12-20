class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       if (nums.size() == 3) {
           return nums[0] * nums[1] * nums[2];
       }
        sort(nums.begin(), nums.end());
        
        int a = nums[nums.size() - 3] * 
             nums[nums.size() - 2] * nums[nums.size() - 1];
        int b = nums[0] * nums[1] * nums[nums.size() - 1];
        //int c = INT_MIN;
        //int d = INT_MIN;
        
        bool isPos = false;
        
        if (nums[0] >= 0 || nums[nums.size() - 1] <= 0) {
            // all numbers are positive or negative
            return a;
        } 
        return max(a,b);
    }
};