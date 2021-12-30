class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int half = (0 + nums.size()) / 2;
        
        vector<int> sub = nums;
        int s1 = nums.size() - 1 - half;
        int s2 = nums.size() - 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = sub[s1];
                s1--;
            } else {
                nums[i] = sub[s2];
                s2--;
            }
        }
    }
};