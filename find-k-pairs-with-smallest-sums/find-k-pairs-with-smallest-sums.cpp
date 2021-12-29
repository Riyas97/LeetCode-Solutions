class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>,
           vector<tuple<int, int, int> >,
           greater<tuple<int, int, int> > >
           g;
        
        g.push(std::tuple(nums1[0] + nums2[0], 0, 0));
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < k; i++) {
            
            if (g.empty()) {
                break;
            }
            
            tuple <int, int, int> tup = g.top();
            int a = get<0>(tup);
            int b = get<1>(tup);
            int c = get<2>(tup);
          
            g.pop();
            
            while (!g.empty() && get<0>(g.top()) == a && 
                   get<1>(g.top()) == b && 
                   get<2>(g.top()) == c) {
                g.pop();
            } 
            cout << b << c << "\n";
            ans.push_back({nums1[b], nums2[c]});
            
            if (b < nums1.size() - 1) {
                g.push(std::tuple(nums1[b+1] + nums2[c], b+1, c));
            }
            
            if (c < nums2.size() - 1) {
                g.push(std::tuple(nums1[b] + nums2[c+1], b, c+1));
            }
            
        }
        return ans;
    }
};