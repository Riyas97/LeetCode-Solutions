class Solution {
public:
    int bs(int s, int e, int val, 
          vector<int>& days) {
        int ret = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (days[m] == val) {
                return m + 1;
            } else if (days[m] < val) {
                s = m + 1;
            } else {
                ret = m;
                e = m - 1;
            }
        }
        return ret;
    }
    
    
    int dp(vector<int>& days, vector<int>& costs, int ind,
          vector<int>& mcostarr) {
        if (ind == days.size() - 1) {
            return min({costs[0], costs[1], costs[2]});
        }
        
        if (ind >= days.size()) {
            return 0;
        }
        
        if (mcostarr[ind] != -1) {
            return mcostarr[ind];
        }
        
        int mcost = INT_MAX;
        for (int i = 0; i <= 2; i++) {
            if (i == 0) {
                // one day
                int val = costs[0] + dp(days, costs, ind+1,
                                      mcostarr);
                mcost = min(mcost, val);
            } else if (i == 1) {
                // 7-day
                int dt = bs(ind, days.size() - 1, 
                           days[ind] + 6, days);
                int val = costs[1];
                if (dt < 0 || dt >= days.size()) {
                    mcost = min(mcost, val);
                } else {
                    val += dp(days, costs, dt, mcostarr);
                    mcost = min(mcost, val);
                }
                
            } else {
                //30 day
                int dt = bs(ind, days.size() - 1, 
                           days[ind] + 29, days);
                int val = costs[2];
                if (dt < 0 || dt >= days.size()) {
                    mcost = min(mcost, val);
                } else {
                    val += dp(days, costs, dt, mcostarr);
                    mcost = min(mcost, val);
                }
            }
        }
        
        mcostarr[ind] = mcost;
        return mcostarr[ind];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> mcostarr(days.size(), -1);
        return dp(days, costs, 0, mcostarr);
    }
};