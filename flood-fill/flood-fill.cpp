class Solution {
public:
    void dfs(int x, int y, int xf, int yf, vector<vector<int>>& image, int val, int n) {
        if (x < 0 || x > xf || y < 0 || y > yf || image[x][y] != val) {
            return;
        }
        image[x][y] = n;
        
        dfs(x-1, y, xf, yf, image, val, n);
        dfs(x+1, y, xf, yf, image, val, n);
        dfs(x, y-1, xf, yf, image, val, n);
        dfs(x, y+1, xf, yf, image, val, n);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        dfs(sr, sc, m-1, n-1, image, image[sr][sc], newColor);
        return image;
    }
};