class Solution {
public:
    bool isPal(int i, int j, string s) {
        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        string str = s;
        
        if (s.length() == 1) {
            return true;
        }
        
        for (int i = 0; i <= (s.length() - 1) / 2; i++) {
            if (s[i] == s[s.length() - 1 - i]) {
                continue;
            } else {
                if (!isPal(i + 1, s.length() - 1 - i, s)
                   && !isPal(i, s.length() - 1 - i - 1, s)) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        return true;
    }
};