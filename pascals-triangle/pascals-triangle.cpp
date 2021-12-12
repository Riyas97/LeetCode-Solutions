class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <int> a;
        a.push_back(1);
        vector<vector<int>> ans;
        ans.push_back(a);
        for (int i = 1; i < numRows; i++) {
            vector <int> b;
            for (int j = 0; j <= i; j += 1) {
                if (j == 0 || j == i) {
                    b.push_back(1);
                } else {
                    b.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};