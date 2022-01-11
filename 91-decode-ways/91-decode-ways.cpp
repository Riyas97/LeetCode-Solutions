class Solution {
public:
    void recurse(int& ans, string s, int ind,
                vector<int>& dp) {
        //cout << ind << " ";
        if (ind == s.length() - 1) {
            if (s[ind] != '0') {
                //cout << s[ind];
                dp[ind] = 1;
                ans++;
            } else {
                dp[ind] = 0;
            }
            return;
        }
        
        if (ind == s.length()) {
            //cout << "yes";
            ans++;
            return;
        }
        
        if (dp[ind] != -1) {
            ans += dp[ind];
            return;
        } 
        
        int prev = ans;
        // just one
        if (s[ind] != '0') {
            recurse(ans, s, ind+1, dp); 
        }
        // two
        if (s[ind] == '1' || 
            (s[ind] == '2' && s[ind+1] - '0' >= 0 &&  
             s[ind+1] - '0' <= 6)) {
            recurse(ans, s, ind+2, dp);
        }
        
        if (ans > prev) {
            dp[ind] = ans - prev;    
        } else {
            dp[ind] = 0;
        }
        
        return;
    }
    
    int numDecodings(string s) {
        int ans = 0;
        vector<int> dp(s.length(), -1);
        recurse(ans, s, 0, dp);
        return ans;
    }
};