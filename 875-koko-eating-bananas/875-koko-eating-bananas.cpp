class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int s = 1;
        int e = piles[piles.size() - 1];
        int ans = -1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            int hours = 0;
            
            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] <= m) {
                    hours++;
                } else {
                    if (piles[i] % m != 0) {
                        hours++;
                    }
                    hours += (piles[i] / m);
                }
            }
            
            if (hours <= h) {
                e = m - 1;
                ans = m;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};