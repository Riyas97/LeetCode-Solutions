class NumMatrix {
public:
    /*
    3 3 4 8 10
    5 11 14 16 17
    1 3 3 4 9
    
    */
    
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        vector<int> v1(matrix[0].size(), 0);
        vector<vector<int>> v2(matrix.size(), v1);
        for (int i = 0; i < matrix.size(); i++) {
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                if (i == 0) {
                    v2[i][j] = sum;
                } else {
                    v2[i][j] = v2[i-1][j] + sum;
                }
                cout << v2[i][j] << " ";
            }
            cout << "\n";
        }
        sum = v2;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans;
        if (row1 == 0 && col1 == 0) {
            ans = sum[row2][col2];
        } else if (row1 == 0) {
            ans = sum[row2][col2] - sum[row2][col1-1];
        } else if (col1 == 0) {
            ans = sum[row2][col2] - sum[row1-1][col2];
        } else {
            ans = sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */