class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector <int> wid;
        for (int i = 0; i < points.size(); i++) {
            wid.push_back(points[i][0]);
        }
        sort(wid.begin(), wid.end());
        int ans = 0;
        int prev = wid[0];
        for (int i = 1; i < wid.size(); i++) {
            int diff = wid[i] - prev;
            ans = max(ans, diff);
            prev = wid[i];
        }
        return ans;
    }
};