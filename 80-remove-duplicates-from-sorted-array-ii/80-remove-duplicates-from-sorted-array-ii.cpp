class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st = 1;
        int limit = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                limit++;
                if (limit >= 2) {
                    continue;
                } else {
                    nums[st] = nums[i];
                    st++; 
                }
            } else {
                limit = 0;
                nums[st] = nums[i];
                st++;
            }
        }
        return st;
    }
};