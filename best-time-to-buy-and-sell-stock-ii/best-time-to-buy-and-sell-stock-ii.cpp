class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int locMax = INT_MIN;
        int val = prices[0];
        int peak = prices[0];
        bool transa = false;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < val) {
                if (locMax != INT_MIN) {
                    p += locMax;
                    locMax = INT_MIN;
                }
                val = prices[i];
                peak = prices[i];
            } else if (prices[i] > peak) {
                peak = prices[i];
                locMax = max(locMax, peak - val);
            } else if (prices[i] < peak && prices[i] >= val) {
                p += locMax;
                locMax = INT_MIN;
                val = prices[i];
                peak = prices[i];
            }
        }
        
        if (locMax != INT_MIN) {
            p += locMax;
            locMax = INT_MIN;
        }
        
        return p;
        
        
    }
};