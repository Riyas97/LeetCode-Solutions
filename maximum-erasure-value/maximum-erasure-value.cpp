class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max = 0;
        int curr = 0;
        int s = 0;
        int e = 0;
        
        unordered_map <int, int> m;
        
        while (e < nums.size()) {
            if (m.find(nums[e]) == m.end()) {
                // new element
                m[nums[e]] = 1;
                curr += nums[e];
                e += 1;
            } else {
                // element already there
                while (nums[s] != nums[e]) {
                    curr -= nums[s];
                    m.erase(nums[s]);
                    s += 1;
                }
                s += 1;
                e += 1;
            }
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
};