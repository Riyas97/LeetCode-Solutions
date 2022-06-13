class Solution {
public:
    int dp(vector<vector<int>>& triangle, 
            vector<vector<int>>& vect, int row, int ind) {
        if (row == triangle.size()) {
            return 0;
        }
        if (vect[row][ind] != -1) {
            return vect[row][ind];
        }
        vect[row][ind] = triangle[row][ind] + min(
            dp(triangle, vect, row+1, ind), 
            dp(triangle, vect, row+1, ind+1));
        return vect[row][ind];        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> v(triangle[triangle.size()-1].size(), -1);
        vector<vector<int>> vect(triangle.size(), v);
        return dp(triangle, vect, 0, 0);
    }
};