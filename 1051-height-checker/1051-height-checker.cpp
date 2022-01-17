class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dup = heights;
        sort(dup.begin(), dup.end());
        
        int ans = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != dup[i]) {
                ans++;
            }
        }
        return ans;
    }
};