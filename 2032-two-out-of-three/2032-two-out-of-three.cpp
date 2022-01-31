class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector <int> c1 (101, 0);
        vector <int> c2 (101, 0);
        vector <int> c3 (101, 0);
        for (int i = 0; i < nums1.size(); i++) {
            c1[nums1[i]] = 1;
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            c2[nums2[i]] = 1;
        }
        
        for (int i = 0; i < nums3.size(); i++) {
            c3[nums3[i]] = 1;
        }
        
        vector <int> ans;
        for (int i = 1; i <= 100; i++) {
            int val = c1[i] + c2[i] + c3[i];
            if (val >= 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};