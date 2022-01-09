class Solution {
public:
    
    struct hash_tuple {
        template <class T1, class T2, class T3>
        size_t operator()(
            const tuple<T1, T2, T3>& x)
            const
        {
            return get<0>(x)
                   ^ get<1>(x)
                   ^ get<2>(x);
        }
    };
    
    int dp(int row, int c1, int c2, vector<vector<int>>& grid,
           vector<vector<vector<int>>>& um) {
        
        if (row >= grid.size() || c1 < 0 || c2 < 0 || 
           c1 >= grid[0].size() || c2 >= grid[0].size()) {
            return 0;
        }
        
        tuple<int, int, int> t1(row, c1, c2);
        
        if (um[row][c1][c2] != -1) {
            return um[row][c1][c2];
        }
        
        int val = 0;
        if (c1 == c2) {
            val += grid[row][c1];
        } else {
            val = grid[row][c1] + grid[row][c2];
        }
        
        if (row == grid.size() - 1) {
            um[row][c1][c2] = val;
            return um[row][c1][c2];
        }
        
        int val1 = -1;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int a = dp(row+1, c1+i, c2+j, grid,um);
                val1 = max(val1, a);
            }
        }
        
        val += val1;
        um[row][c1][c2] = val;
        return um[row][c1][c2];
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        //unordered_map <tuple<int, int, int>,int,hash_tuple> um;
        vector <int> v1 (grid[0].size(), -1);
        vector <vector<int>> v2 (grid[0].size(), v1);
        vector<vector<vector<int>>> um(grid.size(), v2);
        return dp(0, 0, grid[0].size()-1, grid, um);
    }
};