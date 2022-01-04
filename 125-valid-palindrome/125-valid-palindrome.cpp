class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] - 'a' >= 0 &&
               s[i] - 'a' <= 25) {
                str += s[i];
            } else if (s[i] - 'A' >= 0 &&
               s[i] - 'A' <= 25) {
                s[i] += 32;
                str += s[i];
            } else if (s[i] - '0' >= 0 &&
                      s[i] - '0' <= 9) {
                str += s[i];
            }
        }
        string str2 = str;
        reverse(str2.begin(), str2.end());
        if (str == str2) {
            return true;
        }
        return false;
    }
};