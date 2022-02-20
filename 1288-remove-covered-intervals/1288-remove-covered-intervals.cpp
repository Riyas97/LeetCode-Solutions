class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        sort(intervals.begin(), intervals.end(), [this]
            (vector<int> a, vector<int> b) {
               if (a[0] != b[0]) {
                   return a[0] < b[0];
               } else {
                   return a[1] >= b[1];
               } 
            });
        int st = 0;
        int s1 = intervals[st][0];
        int s2 = intervals[st][1];
        st = 1;
        while (st < intervals.size()) {
            //cout << intervals[st][0] << " " 
            //    << intervals[st][1] << "\n";
            if (s1 <= intervals[st][0] &&
               intervals[st][1] <= s2) {
                st++;
            } else {
                s1 = intervals[st][0];
                s2 = intervals[st][1];
                st++;
                ans++;
            }
        }
        return ans;
    }
};