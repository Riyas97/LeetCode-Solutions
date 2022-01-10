class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            v[i] = sum;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int left = v[i] - nums[i];
            int right = v[nums.size() - 1] - v[i];
            
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};