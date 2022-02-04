class Solution {
public:
    int pathway(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& dp) {
        if (i == grid.size()) {
            return j;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = -1;
        
        if (grid[i][j] == 1) {
            // need to look right
            int nexj = j + 1;
            if (nexj == grid[0].size()) {
                // stuck
                ans = -1;
            } else if (grid[i][nexj] == -1) {
                ans = -1;
            } else {
                ans = pathway(i+1, nexj, grid, dp);
            }
        } else {
            // need to look left
            int nexj = j - 1;
            if (nexj == -1) {
                // stuck
                ans = -1;
            } else if (grid[i][nexj] == 1) {
                ans = -1;
            } else {
                ans = pathway(i+1, nexj, grid, dp);
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<int> cols(grid[0].size(), -1);
        vector<vector<int>> dp(grid.size(), cols);
        for (int j = 0; j < grid[0].size(); j++) {
            int num = pathway(0, j, grid, dp);
            ans.push_back(num);
        }
        return ans;
    }
};