class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_set <int> u;
        bool repeat = false;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                if (!repeat && k == 0) {
                    ans += 1;
                }
                repeat = true;
                continue;
            }
            repeat = false;
            int num = nums[i] - k;
            if (u.find(num) != u.end()) {
                ans += 1;
            }
            u.insert(nums[i]);
        }
        return ans;
    }
};