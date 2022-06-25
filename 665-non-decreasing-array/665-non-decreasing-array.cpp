class Solution {
public:
    /*
    3 6 2
    */
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] <= nums[i+1]) {
                continue;
            }
            if (changed) {
                return false;
            }
            changed = true;
            // conditions where u change i+1
            if ((i != 0 && nums[i+1] < nums[i-1])) {
                nums[i+1] = nums[i]; 
            } else {
                // conditions where u change i
                continue;
            }
        }
        return true;
    }
};