class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i != 0) {
                continue;
            } 
                
            bool is = true;
            string prev = s.substr(0, i);
            string cs = s.substr(i, s.length() - i);
            while (cs.length() > 0) {
                string ds = cs.substr(0, i);
                if (ds != prev) {
                    is = false;
                    break;
                }
                prev = ds;
                cs = cs.substr(i, cs.length() - i);
            }
            if (is) {
                return true;
            }
        }
        return false;
    }
};