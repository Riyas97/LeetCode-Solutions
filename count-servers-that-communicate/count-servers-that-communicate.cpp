class Solution {
public:
    bool dfs(int x, int y, int xf, int yf, vector<vector<int>>& grid, int a,
            int i, int j) {
        cout  << x << "," << y << "\n";
        if (x < 0 || x > xf || y < 0 || y > yf) {
            return false;
        }
        
        
        if ((x != i || y != j) && grid[x][y] == 1) {
            cout  << "good" << "\n";
            return true;
        }
        
        bool res = false;
        
        if (a == 1) {
            res = dfs(x-1, y, xf, yf, grid, 1, i, j);
        }
        if (a == 2) {
            res = dfs(x+1, y, xf, yf, grid, 2, i, j);
        }
    
        if (a == 3) {
            res = dfs(x, y-1, xf, yf, grid, 3, i, j);
        }
        
        if (a == 4) {
            res = dfs(x, y+1, xf, yf, grid, 4, i, j);    
        }
        
        return res;
        
    }
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int t = 0;
        bool rec = false;
        vector <bool> v (n, false);
        for (int i = 0; i < m; i++) {
            rec = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (v[j]) {
                        t += 1;
                    }
                    else if (!rec) {
                        bool res1 = dfs(i, j, m-1, n-1, grid, 1, i, j);
                        bool res2 = dfs(i, j, m-1, n-1, grid, 2, i, j);
                        bool res3 = dfs(i, j, m-1, n-1, grid, 3, i, j); 
                        bool res4 = dfs(i, j, m-1, n-1, grid, 4, i, j);
                        cout << res1 << res2 << res3 << res4 << '\n';
                        bool res = res1 || res2 || res3 || res4; 
                        if (res) {
                            t += 1;
                            rec = true;
                            v[j] = true;
                        }    
                    } else {
                        t += 1;
                    }
                    
                    
                }
            }
        }
        return t;
    }
};