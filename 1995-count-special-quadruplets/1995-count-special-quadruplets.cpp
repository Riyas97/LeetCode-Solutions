class Solution {
public:
    // idea: nums[a] + nums[b] = nums[d] - nums[c]
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        unordered_map <int, vector<int>> um;
        for (int b = 1; b <= nums.size() - 3; b++) {
            for (int a = 0; a < b; a++) {
                um[nums[a] + nums[b]].push_back(b);
            }
        }
        
        for (int d = 3; d <= nums.size() - 1; d++) {
            for (int c = 2; c < d; c++) {
                int s = nums[d] - nums[c];
                if (um.find(s) == um.end()) {
                    continue;
                } else {
                    vector <int> v = um[s];
                    for (int i = 0; i < v.size(); i++) {
                        if (v[i] < c) {
                            ans++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};