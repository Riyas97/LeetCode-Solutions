class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        unordered_set<int> s2;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (s.find(nums2[i]) != s.end()) {
                if (s2.find(nums2[i]) == s2.end()) {
                    s2.insert(nums2[i]);
                    ans.push_back(nums2[i]);
                }
            }
        }
        return ans;
    }
};