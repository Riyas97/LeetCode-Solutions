class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        for (int i = 0; i < s.length(); i++) {
            string str = s.substr(i, s.length() - i);
            string str2 = s.substr(0, i);
            string str3 = str + str2;
            if (str3 == goal) {
                return true;
            }
        }
        return false;
    }
};