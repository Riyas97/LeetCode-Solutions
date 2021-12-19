class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int& tlr, int& tlc, int& brr, int& brc) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] != 1) {
            return;
        }
        
        land[i][j] = 2;
        
        if (i <= tlr && j <= tlc) {
            tlr = i;
            tlc = j;
        }
        
        if (i >= brr && j >= brc) {
            brr = i;
            brc = j;
        }
        
        dfs(land, i-1, j, tlr, tlc, brr, brc);
        dfs(land, i+1, j, tlr, tlc, brr, brc);
        dfs(land, i, j-1, tlr, tlc, brr, brc); 
        dfs(land, i, j+1, tlr, tlc, brr, brc);
        
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++) {
           for (int j = 0; j < land[0].size(); j++) {
               if (land[i][j] == 1) {
                   int tlr = i;
                   int tlc = j;
                   int brr = i;
                   int brc = j;
                   dfs(land, i, j, tlr, tlc, brr, brc);
                   vector<int> vect;
                   vect.push_back(tlr);
                   vect.push_back(tlc);
                   vect.push_back(brr);
                   vect.push_back(brc);
                   ans.push_back(vect);
               }
           }
        }
        return ans;
    }
};