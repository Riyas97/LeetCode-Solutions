class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<int> v(image[0].size(), 0);
        vector<vector<int>> ans(image.size(),v);
        
        for (int i = 0; i < image.size(); i++) {
            for (int j = image[i].size()-1; j >= 0; j--) {
                ans[i][image[i].size()-1-j] = 
                    abs(image[i][j] - 1);
            }
        }
        
        return ans;
    }
};