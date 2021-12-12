class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int a = r * c;
        int m = mat.size();
        int n = mat[0].size();
        if (m*n < a || m*n > a) {
            return mat;
        }
        int e = 0;
        int f = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            vector <int> a1;
            for (int j = 0; j < c; j++) {
                
                a1.push_back(mat[e][f]);
                f += 1;
                
                if (f == n) {
                    f = 0;
                    e += 1;
                }
            }
            ans.push_back(a1);
        }
        return ans;
    }
};