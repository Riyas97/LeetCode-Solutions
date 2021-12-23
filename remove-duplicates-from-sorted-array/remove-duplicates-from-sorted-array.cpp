class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int dup = 1;
        int lastV = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == lastV) {
                if (dup == -1) {
                    dup = min(dup, i);
                }
                //cout << i;
            } else if (nums[i] != lastV) {
                lastV = nums[i];
                nums[dup] = nums[i];
                dup += 1;
            }
        }
        
        return dup;
    }
};