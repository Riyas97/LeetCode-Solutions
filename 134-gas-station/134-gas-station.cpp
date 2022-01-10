class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // leftover + topup should be more than/equal cost
        int ans = -1;
        int sum = 0;
        int lsum = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (ans == -1) {
                if (gas[i] >= cost[i]) {
                    ans = i;
                    lsum = gas[i] - cost[i];
                } else {
                    sum += gas[i] - cost[i];
                }
            } else {
               if (gas[i] >= cost[i]) {
                    lsum += gas[i] - cost[i];
                } else {
                   lsum += gas[i] - cost[i];
                   if (lsum < 0) {
                       ans = -1;
                       sum += lsum;
                   } else {
                       continue;
                   }
               }
            }
        }
        
        cout << ans << " " << lsum << " " << sum;
        
        if (ans == -1) {
            return -1;
        } else {
            sum += lsum;
            if (sum >= 0) {
                return ans;
            }
        }
        return -1;
    }
};