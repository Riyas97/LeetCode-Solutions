class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> u;
        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]]++;
        }
        auto it = u.begin();
        int max = it->second;
        int ans = it->first;
        it++;
        for (it; it != u.end(); it++) {
            if (it->second >= max) {
                max = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};