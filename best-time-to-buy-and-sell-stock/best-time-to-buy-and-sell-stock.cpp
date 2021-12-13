class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        
        int s = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < s) {
                s = prices[i];
            } else {
                int m = prices[i] - s;
                if (m > p) {
                    p = m;
                }
            }
        }
        return p;
    }
};