class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector <int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            int a = target - nums[i];
            if (m.find(a) == m.end()) {
                m.insert(pair<int,int> (nums[i], i));
            } else {
                v.push_back(m[a]);
                v.push_back(i);
            }
        }
        return v;
    }
};