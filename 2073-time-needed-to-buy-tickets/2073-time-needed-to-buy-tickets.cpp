class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tick = tickets[k];
        int ans = tick;
        for (int i = 0; i < k; i++) {
            if (tickets[i] > tick) {
                ans += tick;
            } else {
                ans += tickets[i];
            }
        }
        
        for (int i = k+1; i < tickets.size(); i++) {
            if (tickets[i] > tick - 1) {
                ans += (tick - 1) ;
            } else {
                ans += tickets[i];
            }
        }
        
        return ans;
    }
};