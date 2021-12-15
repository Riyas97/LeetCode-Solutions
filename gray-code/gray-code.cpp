class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> ans;
        
        if (n == 1) {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        
        vector <int> v1 = grayCode(n-1);
        vector <int> v2 = v1;
        reverse(v2.begin(), v2.end());
        
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v1[i]);
        }
        int b = 1 << (n - 1);
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v2[i] + b);
        }
        
        
        return ans;
    }
};