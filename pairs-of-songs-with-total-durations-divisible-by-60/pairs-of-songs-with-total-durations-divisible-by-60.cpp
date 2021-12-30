class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v {60,120,180,240,300,360,420,480,540,
                      600,660,720,780,840,900,960};
        int ans = 0;
        unordered_map<int, int> u;
        for (int i = 0; i < time.size(); i++) {
            if (u.find(time[i]) != u.end()) {
                ans += u[time[i]];
            }
            for (int j = 0; j <= 15; j++) {
                int ad = v[j] - time[i];
                if (ad >= 1) {
                    u[ad]++;
                }
            }
        }
        return ans;
    }
};