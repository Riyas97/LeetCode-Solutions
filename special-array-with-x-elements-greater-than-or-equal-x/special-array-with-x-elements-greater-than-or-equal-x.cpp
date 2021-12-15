class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int j = nums.size() - i;
            
            if (nums[i] >= j) {
                if (i == 0 || nums[i-1] < j) {
                    return j;
                } 
            }
        }
        return -1;
    }
};