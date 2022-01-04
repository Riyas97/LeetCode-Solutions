class Solution {
public:
    bool halvesAreAlike(string s) {
        int num = 0;
        int half = s.size() / 2;
        
        for (int i = 0; i < half; i++) {
            if (s[i] == 'a' || s[i] == 'A') {
                num++;
            } else if (s[i] == 'e' || s[i] == 'E') {
                num++;
            } else if (s[i] == 'i' || s[i] == 'I') {
                num++;
            } else if (s[i] == 'o' || s[i] == 'O') {
                num++;
            } else if (s[i] == 'u' || s[i] == 'U') {
                num++;
            } 
        }
        
        for (int i = half; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'A') {
                num--;
            } else if (s[i] == 'e' || s[i] == 'E') {
                num--;
            } else if (s[i] == 'i' || s[i] == 'I') {
                num--;
            } else if (s[i] == 'o' || s[i] == 'O') {
                num--;
            } else if (s[i] == 'u' || s[i] == 'U') {
                num--;
            } 
        }
        
        if (num == 0) {
            return true;
        }
        return false;
        
    }
};