class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool prev = false;
        for (int i = 0; i < nums.size() - 1; i += 1) {
            if (!prev && nums[i] > nums[i+1]) {
                prev = true;
                if (i == 0) {
                    nums[i] = nums[i+1];
                } else {
                    if (nums[i-1] <= nums[i+1]) {
                        nums[i] = nums[i-1];
                    } else if (nums[i-1] > nums[i+1]) {
                        nums[i+1] = nums[i];
                    }
                }
            } else if (prev && nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};