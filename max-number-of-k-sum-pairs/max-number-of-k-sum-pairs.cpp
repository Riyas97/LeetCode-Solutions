class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int remain = k - nums[i];
            if (m[remain] > 0) {
                m[remain]--;
                ans += 1;
            } else {
                m[nums[i]]++;
            }
        }
        return ans;
    }
};