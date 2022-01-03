class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        int prev = prices[0];
        int st = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prev - 1) {
                prev = prices[i];
            } else {
                if (st != i - 1) {
                    int noterms = i - st;
                    int last = noterms - 1;
                    int first = 1;
                    long long num = ((double) 0.5 *
                               (last - first + 1) * 
                             (first + last));
                    cout << first << last << num << "\n";
                    ans += num;
                }
                st = i;
                prev = prices[i];
            }
        }
        if (st != prices.size() - 1) {
            int i = prices.size();
            int noterms = i - st;
            int last = noterms - 1;
            int first = 1;
            long long num = ((double) 0.5 *
                       (last - first + 1) * (first + last));
            cout << first << last << num << "\n";
            ans += num;
        }
        
        
        return ans;
    }
};