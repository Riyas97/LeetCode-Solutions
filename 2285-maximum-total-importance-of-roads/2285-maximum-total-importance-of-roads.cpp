class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v;
        vector<vector<int>> nodes (n, v);
        vector<vector<int>> compare (n, v);
        vector<int> edgeVals(n, 0);
        
        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        
        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            edgeVals[a] += nodes[b].size();
            edgeVals[b] += nodes[a].size();
        }
        
        for (int i = 0; i < n; i++) {
            compare[i].push_back(nodes[i].size());
            compare[i].push_back(edgeVals[i]);
        }
        
        sort(compare.begin(), compare.end(), [this]
            (vector<int>&a , vector<int>& b) {
                if (a[0] != b[0]) {
                    return a[0] > b[0];
                } else {
                    return a[1] > b[1];
                }
            });
        
        long long ans = 0;
        int st = n;
        for (int i = 0; i < n; i++) {
            long long val = (long long) st * compare[i][0];
            ans += val;
            //cout << i << " " << compare[i][0] << " " << compare[i][1] << "\n";
            st--;
        }
        

        return ans;
        
        
    }
};