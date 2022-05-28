class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int orig = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            orig += i;
        }
        orig += nums.size();
        return (orig - sum);
    }
};