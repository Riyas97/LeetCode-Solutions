class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector <int> v1 (m, 0);
        vector<vector<int>> v (n, v1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //cout << i<< j;
                if (nums1[i] == nums2[j]) {
                    //cout << i << j;
                    if (i != 0 && j != 0) {
                        //cout << i << j;
                        //cout << v[i-1][j-1] << "\n";
                        v[j][i] = 1 + v[j-1][i-1];    
                    } else {
                        v[j][i] = 1;
                    }
                }
            }
        }
        
        
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << i<<j;
                ans = max(ans, v[i][j]);
            }
        }
        
        //cout << v[0][]
        return ans;
    }
};