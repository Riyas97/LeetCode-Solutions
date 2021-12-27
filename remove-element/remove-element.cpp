class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s1 = nums.size();
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val && !found) {
                found = true;
                s1 = i;
            } else if (nums[i] != val && found) {
                nums[s1] = nums[i];
                nums[i] = val;
                s1 += 1;
            }
        }
        return s1;
    }
};