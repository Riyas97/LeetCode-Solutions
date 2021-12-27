class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int ans = 0;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (m != nums.size() - 1 && 
                nums[m] < target && target < nums[m+1]) {
                ans = m + 1;
                break;
            } else if (nums[m] < target) {
                s += 1;
                ans = m + 1;
            } else if (m != 0 && 
                nums[m] > target && target > nums[m-1]) {
                ans = m;
                break;
            } else if (nums[m] > target) {
                e -= 1;
                ans = m;
            }
        }
        return ans;
    }
};