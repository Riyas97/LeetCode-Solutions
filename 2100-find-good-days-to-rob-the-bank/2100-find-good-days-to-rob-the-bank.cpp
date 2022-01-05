class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector <int> inc (security.size(), 0);
        vector <int> dec (security.size(), 0);
        
        for (int i = security.size() - 2; i >= 0; i--) {
            if (security[i] <= security[i+1]) {
                inc[i] = 1 + inc[i+1];        
            }
        }
        
        for (int i = 1; i < security.size(); i++) {
            if (security[i-1] >= security[i]) {
                dec[i] = 1 + dec[i-1];        
            }
        }
        
        vector <int> ans;
        for (int i = 0; i < security.size(); i++) {
            //cout << i << " " << inc[i] << " " << dec[i] << "\n";
            if (inc[i] >= time && dec[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};