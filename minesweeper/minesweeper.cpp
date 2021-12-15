class Solution {
public:
    int isMine(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return 0;
        } else if (board[r][c] == 'M' || board[r][c] == 'X') {
            return 1;
        }
        return 0;
    }
    
    int hasAMine(vector<vector<char>>& board, int r, int c) {
        int ans = 0;
        
        int r1 = r - 1;
        int r2 = r + 1;
        int c1 = c - 1;
        int c2 = c + 1;
        
        ans = isMine(board, r1, c1) + isMine(board, r1, c) + 
            isMine(board, r1, c2) + isMine(board, r, c1) +
            isMine(board, r, c2) + isMine(board, r2, c1) +
            isMine(board, r2, c) + isMine(board, r2, c2);
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return;
        }
        if (board[r][c] == 'E') {
            int a = hasAMine(board, r, c);
            if (a == 0) {
                board[r][c] = 'B'; 
                // do something
                dfs(board, r-1, c);
                dfs(board, r+1, c);
                dfs(board, r, c-1);
                dfs(board, r, c+1);
                dfs(board, r-1, c-1);
                dfs(board, r-1, c+1);
                dfs(board, r+1, c-1);
                dfs(board, r+1, c+1);
            } else {
                char put = '0' + a;
                board[r][c] = put;
            }
        } else if (board[r][c] - '0' >= 1 && board[r][c] - '0' <= 8) {
            //int num = board[r][c] - '0';
        }  
        return;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        
        if (board[r][c] == 'E') {
            dfs(board, r, c); 
            
            return board;
        } else if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        return board;
    }
};