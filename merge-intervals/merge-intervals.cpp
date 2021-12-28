class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map <int, int> m;
        for  (int i = 0; i < intervals.size(); i++) {
            if (m.find(intervals[i][0]) == m.end()) {
                m[intervals[i][0]] = intervals[i][1];
            } else {
                int ma = max(intervals[i][1], m[intervals[i][0]]);
                m[intervals[i][0]] = ma;
            }
        }
        vector<vector<int>> ans;
        vector <int> v1;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (v1.empty()) {
                v1.push_back(it->first);
                v1.push_back(it->second);
            } else {
                int a = it->first;
                if (a >= v1[0] && a <= v1[1]) {
                    int ma = max(it->second, v1[1]);
                    v1[1] = ma;
                } else {
                    ans.push_back(v1);
                    v1.clear();
                    v1.push_back(it->first);
                    v1.push_back(it->second);
                }
            }
        }
        if (!v1.empty()) {
            ans.push_back(v1);
        }
        return ans;
    }
};