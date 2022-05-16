class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> inte = img;
        int rows = img.size();
        int cols = img[0].size();
        if (rows == 1 && cols == 1) {
            return img;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                inte[i][j] += img[i][j-1];
            }
            for (int j = cols-2; j >= 0; j--) {
                inte[i][j] += img[i][j+1];
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int denom = 9;
                int sum = inte[i][j];
                if (i == 0 && i == rows-1) {
                    if (j == 0 || j == cols - 1) {
                        denom = 2;
                    } else {
                        denom = 3;
                    }
                } else if (i == 0 || i == rows-1) {
                    if (j == 0 && j == cols - 1) {
                        denom = 2;
                    } else if (j == 0 || j == cols - 1) {
                        denom = 4;
                    } else {
                        denom = 6;
                    }
                } else if (j == 0 && j == cols - 1) {
                    denom = 3;
                }  else if (j == 0 || j == cols - 1) {
                    denom = 6;
                }
                
                if (i == 0 && i != rows-1) {
                    sum += inte[i+1][j];
                } else if (i == rows-1 && i != 0) {
                    sum += inte[i-1][j];
                } else if (i != 0 || i != rows-1) {
                    sum += inte[i+1][j];
                    sum += inte[i-1][j];
                }
                //cout << i << j << " " << sum << " " << denom << "\n";
                img[i][j] = (int)sum/denom; 
            }
        }
        return img;
    }
};