class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int lsum = 0;
        //vector<int> v (n, 0);
        //vector<vector<int>> vect(m, v);
        vector<vector<int>> vect = mat;
        int st = 0;
        
        for (int j = 0; j < n; j++) {
            lsum = 0;
            st = 0;
            for (int i = 0; i < m; i++) {
                vect[i][j] += lsum;
                if (st == i - k) {
                    lsum -= mat[st][j];
                    st++;
                }
                lsum += mat[i][j];
               
            }
        }
        
        for (int j = 0; j < n; j++) {
            lsum = 0;
            st = m-1;
            for (int i = m-1; i >= 0; i--) {
                vect[i][j] += lsum;
                if (st == i + k) {
                    lsum -= mat[st][j];
                    st--;
                }
                lsum += mat[i][j];
               
            }
        }
        
        vector<vector<int>> orig = vect;
        
        for (int i = 0; i < m; i++) {
            lsum = 0;
            st = 0;
            for (int j = 0; j < n; j++) {
                vect[i][j] += lsum;
                if (st == j - k) {
                    lsum -= orig[i][st];
                    st++;
                }
                lsum += orig[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            lsum = 0;
            st = n-1;
            for (int j = n-1; j >= 0; j--) {
                vect[i][j] += lsum;
                if (st == j + k) {
                    lsum -= orig[i][st];
                    st--;
                }
                lsum += orig[i][j];
            }
        }
        
        return vect;
    }
};