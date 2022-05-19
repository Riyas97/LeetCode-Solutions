class Solution {
public:
    int dp(vector<vector<int>>& matrix, vector<vector<int>>& steps, 
           int i, int j) {
        int x[] = {0,0,-1,1};
        int y[] = {-1,1,0,0};
        int val = 0;
        if (steps[i][j] > 0) {
            return steps[i][j];
        }
        for (int a = 0; a <= 3; a++) {
            int newx = i+x[a];
            int newy = j + y[a];
            if (newx < 0 || newy < 0 || 
                newx >= matrix.size() || newy >= matrix[0].size() ||
                matrix[newx][newy] <= matrix[i][j]) {
                continue;
            } else {
                val = max(val, dp(matrix, steps, newx, newy));
            }
        }
        steps[i][j] = 1 + val;
        return steps[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<int> v(matrix[0].size(), 0);
        vector<vector<int>> steps(matrix.size(), v);
        int msteps = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (steps[i][j] == 0) {
                    msteps = max(msteps, dp(matrix, steps, i, j));
                } else {
                    msteps = max(msteps, steps[i][j]);
                }
                //cout << i << " " << j << " " << steps[i][j] << "\n";
            }
        }
        return msteps;
    }
};