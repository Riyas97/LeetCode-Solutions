class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        unordered_map <int, int> um;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                ans = max(ans, i+1);
            } else {
                if (um.find(count) != um.end()) {
                    int st = um[count];
                    ans = max(ans, i - st);
                } else {
                    um[count] = i;
                }
            }
        }
        return ans;
    }
};

