class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int d = -1;
        int min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= min) {
                min = nums[i];
            } else {
                d = max(d, nums[i] - min);
            }
        }
        return d;
    }
};