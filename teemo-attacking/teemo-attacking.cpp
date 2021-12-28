class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        
        if (timeSeries.size() == 1) {
            return duration;
        }
        
        int val = timeSeries[0] + duration - 1;
        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i] <= val) {
                ans += (timeSeries[i] - timeSeries[i-1]);
                val = timeSeries[i] + duration - 1;
            } else {
                ans += duration;
                val = timeSeries[i] + duration - 1;
            }
        }
        ans += duration;
        return ans;
    }
};