class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map <double, int> count;
        
        for (int i = 0; i < rectangles.size(); i++) {
            double aspect = (double)rectangles[i][0] / rectangles[i][1];
            //cout << aspect << " ";
            count[aspect]++;
        }
        
        long long ans = 0;
        for (auto it = count.begin(); it != count.end(); it++) {
            long long c = it->second;
            if (c > 1) {
                //cout << c;
                long long val = (long long)((c-1) * c);
                ans += (val / 2);
            }
        }
        return ans;
    }
};