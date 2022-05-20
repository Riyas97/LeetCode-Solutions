class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long long> v(obstacleGrid[0].size(), 0);
        vector<vector<long long>> vect(obstacleGrid.size(), v);
        
        for (int i = obstacleGrid.size() - 1; i >= 0; i--) {
            for (int j = obstacleGrid[i].size() - 1; j >= 0; j--) {
                if (i == obstacleGrid.size()-1 && 
                   j == obstacleGrid[i].size()-1) {
                    if (obstacleGrid[i][j] == 0) {
                        vect[i][j] = 1;
                    } else {
                        return 0;
                    }
                } else if (i == obstacleGrid.size()-1 && 
                          obstacleGrid[i][j] == 0) {
                    //cout << i << j << " " << obstacleGrid[i][j] << "\n";
                    vect[i][j] = vect[i][j+1];
                } else if (j == obstacleGrid[i].size()-1 &&
                          obstacleGrid[i][j] == 0) {
                    vect[i][j] = vect[i+1][j];
                } else if (i != obstacleGrid.size()-1 && 
                          j != obstacleGrid[i].size()-1 && 
                          obstacleGrid[i][j] == 0) {
                    vect[i][j] = vect[i+1][j] + vect[i][j+1];
                }
            
            }
        }
        
        
        // for (int i = 0; i < obstacleGrid.size(); i++) {
        //     for (int j = 0; j < obstacleGrid[i].size(); j++) {
        //         cout << vect[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return vect[0][0];
    }
};