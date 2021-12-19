class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        
        for (int i = 0; i < n; i++) {
            vector <int> matVect (n, 0);
            matrix.push_back(matVect);
        }
        
        int value = 1;
        int i = 0;
        int j = 0;
        int i_add = 0;
        int j_add = 1;
        
        int i_left = 0;
        int i_right = n - 1;
        int j_left = 0;
        int j_right = n - 1;
        
        int fig = 1;
        
        while (value <= n * n) {
            matrix[i][j] = value;
            value += 1;
    
            if (fig == 1 && i == i_left && j == j_right) {
                i_add = 1;
                j_add = 0;
                i_left += 1;
                fig = 2;
                cout << i_left;
            }
            else if (fig == 2 && i == i_right && j == j_right ) {
                i_add = 0;
                j_add = -1;
                j_right -= 1;
                fig = 3;
            }
            else if (fig == 3 && i == i_right && j == j_left) {
                i_add = -1;
                j_add = 0;
                i_right -= 1;
                fig = 4;
            }
            else if (fig == 4 && i == i_left && j == j_left) {
                i_add = 0;
                j_add = 1;
                j_left += 1;
                fig = 1;
            }
            
            i += i_add;
            j += j_add;
        }
        return matrix;
    }
};