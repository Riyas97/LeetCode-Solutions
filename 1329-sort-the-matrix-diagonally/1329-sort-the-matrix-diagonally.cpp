class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int t = m + n - 1;
        vector<int> v1(n, -1);
        vector<vector<int>> ans (m, v1);
        
        int sti = m - 1;
        int stj = 0;
        
        while (t > 0) {
            int i = sti;
            int j = stj;
            vector<int> so;
            while (i < m && j < n) {
                so.push_back(mat[i][j]);
                i += 1;
                j += 1;
            }
            
            sort(so.begin(), so.end());
            
            i = sti;
            j = stj;
            int k = 0;
            while (i < m && j < n) {
                ans[i][j] = so[k];
                k += 1;
                i += 1;
                j += 1;
            }
            
            sti -= 1;
            if (sti == -1) {
                sti = 0;
                stj += 1;
            }
            t -= 1;
        }
        return ans;
    }
};