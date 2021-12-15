class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> u;
        set <int> s1;
        
        for (int i = 0; i < s.length(); i++) {
            if (u.find(s[i]) == u.end()) {
                u[s[i]] = i;
                s1.insert(i);
            } else {
                int num = u[s[i]];
                s1.erase(num);
            }
        }
        if (s1.empty()) {
            return -1;
        }
        return *s1.begin();
    }
};