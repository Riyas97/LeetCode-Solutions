class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> v(rows, 0);
        vector<vector<int>> ans(cols, v);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};