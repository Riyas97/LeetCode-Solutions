class Solution {
public:
    int getCost (int st, vector<int>& cost, vector <int>& count) {
        if (st == cost.size() - 1 || 
           st == cost.size() - 2) {
            return cost[st];
        }
        if (count[st] != -1) {
            return count[st];
        }
        count[st] = cost[st] + min(getCost(st+1, cost, count), 
                        getCost(st+2, cost, count));
        return count[st];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        vector<int> count (cost.size(), -1);
        int a = getCost(0, cost, count);
        int b = getCost(1, cost, count);
        return min(a,b);
    }
};