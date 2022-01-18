class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0 && nums[i] != 0) {
                continue;
            } else if (count != 0 && nums[i] != 0) {
                nums[i-count] = nums[i];
            } else if (nums[i] == 0) {
                count += 1;
            }
        }
        
        for (int i = 0; i < count; i++) {
            nums[nums.size() - 1 - i] = 0;
        }
        
    }
};