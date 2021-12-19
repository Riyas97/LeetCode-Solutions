class Solution {
public:
    bool isSub(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& match) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || 
           grid2[i][j] != 1) {
            return match;
        }
        
        grid2[i][j] = 2;
        if (grid1[i][j] != 1) {
            match = false;
        }
        
        isSub(grid1, grid2, i-1, j, match);
        isSub(grid1, grid2, i+1, j, match);
        isSub(grid1, grid2, i, j-1, match); 
        isSub(grid1, grid2, i, j+1, match);
        
        return match;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++) {
           for (int j = 0; j < grid2[0].size(); j++) {
               if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                   bool match = true;
                   isSub(grid1, grid2, i, j, match);
                   if (match == true) {
                       cout << i << " " << j;
                       ans += 1;
                   }    
               }
           }
       }
        return ans;
    }
};