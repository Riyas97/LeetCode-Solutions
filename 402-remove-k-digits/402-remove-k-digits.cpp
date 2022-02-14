class Solution {
public:
    void funct(string num, int i, int k, 
              string& ans) {
        if (k == 0) {
            for (int c = i; c < num.length(); c++) {
                if (ans != "" || num[c] != '0') {
                    ans.push_back(num[c]);
                }
            }
            return;
        }
        
        if (k == (num.length() - i)) {
            return;
        }
        
        int mnum = num[i] - '0';
        int ind = i;
        for (int j = i + 1; j <= i + k; j++) {
            int snum = num[j] - '0';
            if (snum < mnum) {
                mnum = snum;
                ind = j;
            }
        }
        if (ans != "" || mnum != 0) {
            ans.push_back(num[ind]);
        }
        funct(num, ind+1, k - (ind-i), ans);
    }
    
    
    string removeKdigits(string num, int k) {
        string ans = "";
        if (k == num.length()) {
            return "0";
        }
        funct(num, 0, k, ans);
        if (ans == "") {
            return "0";
        }
        return ans;
    }
};