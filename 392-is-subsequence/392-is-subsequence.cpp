class Solution {
public:
    bool dp(string s, string t, 
           int si, int ti) {
        
        if (si == s.length()) {
            return true;
        }
        
        if (ti == t.length()) {
            return false;
        }
        
        for (int i = ti; i < t.length(); i++) {
            if (s[si] == t[i]) {
                return dp(s, t, si + 1, i+1);
            }
        }
        
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) {
            return false;
        }
        if (s.length() == t.length()) {
            if (s == t) {
                return true;
            }
            return false;
        }
        return dp(s, t, 0, 0);
        
    }
};