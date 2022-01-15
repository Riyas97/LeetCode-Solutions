class Solution {
public:
    int balancedStringSplit(string s) {
        int lcount = 0;
        int rcount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                rcount++;
            } else {
                lcount++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                rcount--;
            } else {
                lcount--;
            }
            
            if (lcount == rcount) {
                ans++;
            }
        }
        return ans;
    }
};