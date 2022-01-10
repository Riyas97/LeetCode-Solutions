class Solution {
public:
    string recurse(int n, vector<string>& dp) {
        if (n == 1) {
            string ans = "1";
            dp[0] = ans;
            return dp[0];
        }
        
        if (dp[n-1] != "") {
            return dp[n-1];
        }
        
        string pstr = recurse(n-1, dp);
        int count = 1;
        string ans = "";
        for (int i = 1; i < pstr.length(); i++) {
            if (pstr[i] == pstr[i-1]) {
                count++;
            } else {
                string add = to_string(count) + pstr[i-1];
                ans += add;
                count = 1;
            }
        }
        string add = to_string(count) + 
            pstr[pstr.length() - 1];
        ans += add;
        dp[n-1] = ans;
        return dp[n-1];
    }
    
    
    
    string countAndSay(int n) {
        //"111221"
        //return "312211";
        vector<string> dp (n, "");
        return recurse(n, dp);
    }
};