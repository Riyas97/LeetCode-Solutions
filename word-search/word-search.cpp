class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int k,
            int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }
        
        if (k == word.size() - 1) {
            return true;
        }
        
        board[i][j] = '0';
        bool result = dfs(board, word, k+1, i-1, j) ||
            dfs(board, word, k+1, i+1, j) ||
            dfs(board, word, k+1, i, j-1) || 
            dfs(board, word, k+1, i, j+1);
        board[i][j] = word[k];
        return result;
    }
     
    
    bool exist(vector<vector<char>>& board, string word) {
        bool isExist = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};