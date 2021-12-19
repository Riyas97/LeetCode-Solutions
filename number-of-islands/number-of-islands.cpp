class Solution {
public:
    void isIsland(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '2';
        
        isIsland(grid, i-1, j);
        isIsland(grid, i+1, j);
        isIsland(grid, i, j-1); 
        isIsland(grid, i, j+1);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
           for (int j = 0; j < grid[0].size(); j++) {
               if (grid[i][j] == '1') {
                   isIsland(grid, i, j);
                   ans += 1;   
               }
           }
       }
        return ans;
    }
};