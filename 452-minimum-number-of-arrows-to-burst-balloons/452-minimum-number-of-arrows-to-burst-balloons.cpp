bool comp(vector<int>& x, vector<int>& y) { 
    return x[1] < y[1]; 
}

class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        //[this] 
        //     (vector<int> a, vector<int> b) {
        //         return a[1] < b[1]; 
        //     }
        //    );
        
        int ans = 1;
        int keep = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            //cout << points[i][0] << points[i][1] << " ";
            if (points[i][0] > keep) {
                ans++;
                keep = points[i][1];
            }
        }
        
        
        return ans;
    }
};