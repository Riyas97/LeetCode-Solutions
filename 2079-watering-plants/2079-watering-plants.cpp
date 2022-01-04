class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int left = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (plants[i] <= left) {
                ans++;
                left -= plants[i];
            } else {
                // go back
                ans += i;
                // come back
                ans += (i + 1);
                left = capacity - plants[i];
            }
        }
        
        return ans;
    }
};