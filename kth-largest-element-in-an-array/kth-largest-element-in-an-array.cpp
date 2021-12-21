class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        if (k <= nums.size()) {
            return nums[nums.size() - k];
        }
        return 0;
    }
};