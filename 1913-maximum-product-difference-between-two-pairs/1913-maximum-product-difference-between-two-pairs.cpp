class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[nums.size() - 1] * nums[nums.size() - 2];
        int s = nums[0] * nums[1];
        return l - s;
    }
};