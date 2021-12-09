class Solution {
public:
    void dfs(int x, int y, int xf, int yf, vector<vector<int>>& grid, int &p) {
        if (x < 0 || x > xf || y < 0 || y > yf ) {
            return;
        }
        
        if (grid[x][y] == 0) {
            p += 1;
            return;
        }
        
        if (grid[x][y] != 1) {
            return;
        }
        
        if (x == 0) {
            p += 1;
        }
        
        if (x == xf) {
            p += 1;
        }
        
        if (y == 0) {
            p += 1;
        }
        if (y == yf) {
            p += 1;
        }
        
        grid[x][y] = 2;
        
        dfs(x-1, y, xf, yf, grid, p);
        dfs(x+1, y, xf, yf, grid, p);
        dfs(x, y-1, xf, yf, grid, p);
        dfs(x, y+1, xf, yf, grid, p);
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, m-1, n-1, grid, p);
                    
                }
            }
        }
        return p;
    }
};