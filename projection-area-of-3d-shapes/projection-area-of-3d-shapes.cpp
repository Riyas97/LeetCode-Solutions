class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int x = 0;
        int y = 0;
        int z = 0;
        
        for (int i = 0; i < n; i++) {
            int max = 0;
            int max1 = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > max) {
                    max = grid[i][j];
                }
                
                if (grid[j][i] > max1) {
                    max1 = grid[j][i];
                }
                
                if (grid[i][j] != 0) {
                    z += 1;
                }
            }
            cout << max << max1;
            x += max;
            y += max1;
        }
        return x + y + z;
    }
};