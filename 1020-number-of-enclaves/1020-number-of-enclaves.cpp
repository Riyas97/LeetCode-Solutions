class Solution {
public:
    
    void boundary(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || 
           j < 0 || j >= grid[0].size() ||
           grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        
        boundary(grid, i-1, j);
        boundary(grid, i+1, j);
        boundary(grid, i, j-1);
        boundary(grid, i, j+1);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[0][j] == 1) {
                boundary(grid, 0, j);
            }
            if (grid[grid.size() - 1][j] == 1) {
                boundary(grid, grid.size() - 1, j);
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 1) {
                //cout << "yes";
                boundary(grid, i, 0);
            }
            if (grid[i][grid[i].size() - 1] == 1) {
                boundary(grid, i, grid[i].size() - 1);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
        
        
    }
};