class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int st = 0;
        for (int i = 0; i < gain.size(); i++) {
            st += gain[i];
            ans = max(ans, st);
        }
        return ans;
    }
};