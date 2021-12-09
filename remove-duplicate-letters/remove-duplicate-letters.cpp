class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector <int> v (26, 0);
        vector <bool> a (26, false);
        
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a'] += 1;
        }
        string res = "";
        
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a'] -= 1;
            
            if (a[s[i] - 'a'] == false) {
                while (res.size() > 0 && res.back() > s[i] && v[res.back() - 'a'] > 0 ) {
                    a[res.back() - 'a'] = false;
                    res.pop_back();
                }
                
                a[s[i] - 'a'] = true;
                res += s[i];
            }
            
        }
        return res;
        
    }
};