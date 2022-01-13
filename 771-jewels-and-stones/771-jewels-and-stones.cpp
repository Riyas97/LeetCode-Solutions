class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set <char> us;
        for (int i = 0; i < jewels.length(); i++) {
            us.insert(jewels[i]);
        }
        int ans = 0;
        for (int i = 0; i < stones.length(); i++) {
            if (us.find(stones[i]) != us.end()) {
                ans++;
            }
        }
        
        return ans;
    }
};