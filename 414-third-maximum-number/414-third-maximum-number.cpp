class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int firstmax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            firstmax = max(firstmax, nums[i]);
        }
        
        if (nums.size() < 3) {
            return firstmax;
        }
        
        int secondmax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != firstmax) {
                secondmax = max(secondmax, nums[i]);
            }
        }
        
        int ans = INT_MIN;
        bool flag = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != firstmax && nums[i] != secondmax) {
                if (nums[i] >= ans) {
                    flag = true;
                    ans = nums[i];
                }
            }
        }
        
        if (flag) {
            return ans;
        } 
        return firstmax;
    }
};