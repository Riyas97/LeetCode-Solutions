class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mnum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mnum = min(mnum, sum);
        }
        if (mnum > 0) {
            return 1;
        } else {
            return (-1 * mnum) + 1;
        }
    }
};