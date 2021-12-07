class Solution {
public:
    void create(vector<string> &ans, int open, int close, int n, string s) {
        
        if (open == close && open == n) {
            ans.push_back(s);
            return;
        }
        
        if (open > n) {
            return;
        }
        if (close > n) {
            return;
        }
        if (close > open) {
            return;
        }
        
        create(ans, open+1, close, n, s+"(");
        create(ans, open, close+1, n, s+")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        create(ans, 1, 0, n, s);
        return ans;
    }
};