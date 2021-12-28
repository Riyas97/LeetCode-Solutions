class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }
        if (nums.size() == 2) {
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return;
        }
        bool desc = true;
        int index = -1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                desc = false;
                index = i - 1;
            }
        }
        if (desc) {
            sort(nums.begin(), nums.end());
        } else {
            sort(nums.begin() + index + 1, nums.end());
        
            
            for (int i = index + 1; i < nums.size(); i++) {
                if (nums[i] > nums[index]) {
                    cout << index << i;
                    
                    int temp = nums[i];
                    nums[i] = nums[index];
                    nums[index] = temp;
                    break;
                }
            }
            
            
            
        }
        
    }
};