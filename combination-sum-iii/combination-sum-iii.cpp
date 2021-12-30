class Solution {
public:
    void backtrack(int k, vector<vector<int>>& ans,
                  int n, int ind, vector<int>& vect,
                  int& sum) {
        
        if (vect.size() == k && sum == n) {
            ans.push_back(vect);
            return;
        }
        
        if (sum > n) {
            return;
        }
        
        if (vect.size() >= k) {
            return;
        }
        
        for (int i = ind; i <= 9 ; i++) {
            vect.push_back(i);
            sum += i;
                
            if (sum > n) {
                vect.pop_back();
                sum -= i;
                return;
            }
            
            backtrack(k, ans, n, i+1, vect, sum);
            vect.pop_back();
            sum -= i;
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vect;
        int sum = 0;
        backtrack(k, ans, n, 1, vect, sum);
        return ans;
    }
};