class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector <int> v1 (matrix[0].size(), 0);
        vector <vector<int>> v2 (matrix.size(), v1);
        
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    continue;
                } 
                if (i == matrix.size() - 1 || 
                   j == matrix[0].size() - 1) {
                    v2[i][j] = matrix[i][j];
                } else {
                    int a = min({v2[i+1][j], 
                                v2[i+1][j+1],
                                v2[i][j+1]}); 
                    v2[i][j] = a + 1;
                }
            }
        }
        
        
        
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << v2[i][j] << " ";
                ans += v2[i][j];
            }
            cout << "\n";
        }
        
        return ans;
    }
};