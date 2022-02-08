class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int keep = piles.size() / 3;
        int ans = 0;
        
        for (int i = piles.size() - 2; i >= keep; i -= 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};