class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<tuple<double,int,int>> vect;
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            vect.push_back(make_tuple(dist,x,y));
        };
        
        sort(vect.begin(), vect.end(), [this]
            (tuple<double,int,int>t1,
             tuple<double,int,int>t2) {
                return get<0>(t1) < get<0>(t2);
            });
        
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back({get<1>(vect[i]), 
                          get<2>(vect[i])});
        };
        
        return ans;
    }
};


