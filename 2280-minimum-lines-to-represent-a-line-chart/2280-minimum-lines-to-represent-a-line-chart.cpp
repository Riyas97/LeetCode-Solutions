class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) {
            return 0;
        }
        sort(stockPrices.begin(), stockPrices.end(), [this]
            (vector<int>& a, vector<int>& b) {
                return a[0] < b[0];
            }
        );
        long double prev_avg = (long double)(stockPrices[1][1] - stockPrices[0][1]) / (long double)
            (stockPrices[1][0] - stockPrices[0][0]);
        int ans = 0;
        for (int i = 2; i < stockPrices.size(); i++) {
            long double avg = (long double)((stockPrices[i][1] - stockPrices[i-1][1]) / (long double)
                (stockPrices[i][0] - stockPrices[i-1][0]));
            if (avg == prev_avg) {
                continue;
            } else {
                ans++;
                prev_avg = avg;
            }
        }
        ans++;
        return ans;
    }
};