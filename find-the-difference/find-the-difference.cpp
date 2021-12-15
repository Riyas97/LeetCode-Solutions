class Solution {
public:
    char findTheDifference(string s, string t) {
        vector <int> v (26, 0);
        
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a'] += 1;
            v[t[i] - 'a'] -= 1;
        }
        v[t[t.length() - 1] - 'a'] -= 1;
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                char c = 'a' + i;
                return c;
            }
        }
        return 'a';
    }
};