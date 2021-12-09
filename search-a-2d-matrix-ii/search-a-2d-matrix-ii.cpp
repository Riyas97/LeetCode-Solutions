class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int s = 0;
        int e = matrix.size() - 1;
        int ts = 0;
        int te = -1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            if (matrix[m][0] == target) {
                return true;
            } else {
                if (matrix[m][0] < target) {
                    te = m;
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        
        if (te == -1) {
            return false;
        }
        
        for (int i = 0; i <= te; i++) {
            int as = 0;
            int ae = matrix[i].size() - 1;
            
            while (as <= ae) {
                int am = (as + ae) / 2;
                if (matrix[i][am] == target) {
                    return true;
                } else {
                    if (matrix[i][am] > target) {
                        ae = am - 1;
                    } else {
                        as = am + 1;
                    }
                }
            }
        }
        
        
        return false;
    }
};