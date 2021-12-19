class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <int> ans;
        int values = m * n;
        int i = 0;
        int j = 0;
        int i_add = 0;
        int j_add = 1;
        
        int i_left = 0;
        int i_right = matrix.size() - 1;
        int j_left = 0;
        int j_right = matrix[0].size() - 1;
        
       
        int fig = 1;
        
        while (values--) {
            ans.push_back(matrix[i][j]);
    
            if (fig == 1 && i == i_left && j == j_right) {
                i_add = 1;
                j_add = 0;
                i_left += 1;
                fig = 2;
                cout << i_left;
            }
            else if (fig == 2 && i == i_right && j == j_right ) {
                i_add = 0;
                j_add = -1;
                j_right -= 1;
                fig = 3;
            }
            else if (fig == 3 && i == i_right && j == j_left) {
                i_add = -1;
                j_add = 0;
                i_right -= 1;
                fig = 4;
            }
            else if (fig == 4 && i == i_left && j == j_left) {
                i_add = 0;
                j_add = 1;
                j_left += 1;
                fig = 1;
            }
            
            i += i_add;
            j += j_add;
        }
        return ans;
    }
};