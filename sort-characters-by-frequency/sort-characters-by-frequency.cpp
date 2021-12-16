class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> u1;
        map <int, unordered_set<char>> u2;
        
        for (int i = 0; i < s.length(); i++) {
            if (u1[s[i]] == 0) {
                u1[s[i]] = 1;
                
                if (u2.find(1) == u2.end()) {
                    unordered_set <char> v;
                    v.insert(s[i]);
                    u2[1] = v;
                } else {
                    u2[1].insert(s[i]);
                }
            } else {
                int num = u1[s[i]];
                u2[num].erase(s[i]);
                
                num += 1;
                u1[s[i]] = num;
                
                if (u2.find(num) == u2.end()) {
                    unordered_set <char> v;
                    v.insert(s[i]);
                    u2[num] = v;
                } else {
                    u2[num].insert(s[i]);
                }
            }
        }
        
        //cout << u1['t'] << u1['r'] << u1['e'];
        
        string ans = "";
        
        for (auto it = u2.rbegin(); it != u2.rend(); it++) {
            int freq = it->first;
            unordered_set <char> us = it->second;
            
            for (auto itt = us.begin(); itt != us.end(); itt++) {
                char c = *itt;
                
                for (int r = 0; r < freq; r++) {
                    ans += c;
                }
                
            }
        }
        
        return ans;
    }
};