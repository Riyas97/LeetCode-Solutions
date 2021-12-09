class Solution {
public:
    void dfs(int x, int y, int xf, int yf, vector<vector<int>>& grid, int &area) {
        if (x < 0 || x > xf || y < 0 || y > yf || grid[x][y] != 1) {
            return;
        }
        grid[x][y] = 0;
        area += 1;
        
        dfs(x-1, y, xf, yf, grid, area);
        dfs(x+1, y, xf, yf, grid, area);
        dfs(x, y-1, xf, yf, grid, area);
        dfs(x, y+1, xf, yf, grid, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int so = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, m-1, n-1, grid, area);
                    if (area > so) {
                        so = area;
                    }
                }
            }
        }
        return so;
    }
};