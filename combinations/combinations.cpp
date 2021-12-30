class Solution {
public:
    
    void backtrack(int k, vector<vector<int>>& ans,
                  int n, int ind, vector<int>& vect) {
        if (vect.size() == k) {
            ans.push_back(vect);
            return;
        }
        
        if (vect.size() > k) {
            return;
        }
        
        for (int i = ind; i <= n ; i++) {
            vect.push_back(i);
            backtrack(k, ans, n, i+1, vect);
            vect.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vect;
        backtrack(k, ans, n, 1, vect);
        return ans;
    }
};