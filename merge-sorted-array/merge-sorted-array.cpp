class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = nums1.size() - 1;
        int b = m - 1;
        int c = nums2.size() - 1;
        
        
        while (a >= 0) {
            if (b == -1) {
                nums1[a] = nums2[c];
                a -= 1;
                c -= 1;
                continue;
            }
            
            if (c == -1) {
                nums1[a] = nums1[b];
                a -= 1;
                b -= 1;
                continue;
            }
            
            if (nums1[b] >= nums2[c]) {
                nums1[a] = nums1[b];
                b -= 1;
                a -= 1;
            } else {
                nums1[a] = nums2[c];
                c -= 1;
                a -= 1;
            }
        }
    }
};