class Solution {
public:
    void dfs(vector<vector<char>>& dp, int i, int j) {
        if (i < 0 || j < 0 || 
            i >= dp.size() || j >= dp[0].size()) {
            return;
        }
        
        if (dp[i][j] != 'O') {
            return;
        }
        
        dp[i][j] = 'V';
        
        dfs(dp, i-1, j);
        dfs(dp, i+1, j);
        dfs(dp, i, j-1);
        dfs(dp, i, j+1);
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> dp;
        dp = board;
        
        // i == 0 and i == dp.size() - 1
        for (int j = 0; j < board[0].size(); j++) {
            if (dp[0][j] == 'O') {
                dfs(dp, 0, j);
            }
            if (dp[dp.size() - 1][j] == 'O') {
                dfs(dp, dp.size() - 1, j);
            }
        }
        
        // j == 0 and j == dp[0].size()
        for (int i = 0; i < board.size(); i++) {
            if (dp[i][0] == 'O') {
                dfs(dp, i, 0);
            }
            if (dp[i][dp[0].size() - 1] == 'O') {
                dfs(dp, i, dp[0].size() - 1);
            }
        }
        
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dp[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
            }
        }
    }
};