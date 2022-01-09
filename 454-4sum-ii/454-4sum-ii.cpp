class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        
        unordered_map <int, int> um;
        int n = nums1.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                um[nums1[i] + nums2[j]]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums3[i] + nums4[j];
                int left = 0 - sum;
                ans += um[left];
            }
        }
    
        return ans;
    }
};