class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ts = matrix.size() * matrix[0].size();
        
        int s = 0;
        int e = ts - 1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            int num = matrix[m / matrix[0].size()][m % matrix[0].size()];
            if (num == target) {
                return true;
            } else {
                if (num < target) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        return false;
    }
};