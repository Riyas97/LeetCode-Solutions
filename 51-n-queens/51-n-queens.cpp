class Solution {
public:
    bool isConsistent(int var, int i, vector<int>& vect) {
        for (int j = 0; j < var; j++) {
            if (vect[j] + (var-j) == i || vect[j] - (var-j) == i) {
                return false;
            } 
        }
        return true;
    }
    
    void backtrack(vector<string>& store, vector<int>& vect,
                   unordered_set<int>& us,
                   int var, int n, vector<vector<string>>& ans) {
        if (var == n) {
            ans.push_back(store);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (us.find(i) == us.end() && 
                isConsistent(var,i, vect)) {
                us.insert(i);
                vect.push_back(i);
                store[var][i] = 'Q';
                backtrack(store, vect, us, var+1, n, ans);
                store[var][i] = '.';
                vect.pop_back();
                us.erase(i);
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> store (n, s);
        vector<vector<string>> ans;
        vector<int> vect;
        unordered_set<int> us;
        backtrack(store, vect, us, 0, n, ans);
        return ans;
    }
};