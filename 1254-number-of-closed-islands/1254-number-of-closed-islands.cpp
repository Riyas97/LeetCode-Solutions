class Solution {
public:
    
    
    
    bool isI(int i, int j, vector<vector<int>>& grid) {
        //cout << i << " " << j << "\n";
        if (i < 0 || i >= grid.size() || j < 0 || 
           j >= grid[0].size()) {
            return false;
        }
        if (grid[i][j] == 1) {
            return true;
        }
        
        if (grid[i][j] == 2) {
            return true;
        }
        
        grid[i][j] = 2;
        
        bool a1 = isI(i-1, j, grid);
        // if (!a1) {
        //     grid[i][j] = 3;
        //     return false;
        // }
        bool a2 = isI(i+1, j, grid);
        // if (!a2) {
        //     grid[i][j] = 3;
        //     return false;
        // }
        bool a3 = isI(i, j-1, grid);
        // if (!a3) {
        //     grid[i][j] = 3;
        //     return false;
        // }
        bool a4 = isI(i, j+1, grid);
        // if (!a4) {
        //     grid[i][j] = 3;
        //     return false;
        // }
        
        if (a1 && a2 && a3 && a4) {
            return true;
        }
        return false;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dupt = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0 && dupt[i][j] == 0) {
                    //cout << i << j << "\n";
                    bool isClosed = false;
                    if (isI(i, j, dupt)) {
                        //cout << "yes" << "\n";
                        ans++;
                    }
                    
                } 
            }
        }
        return ans;
    }
};