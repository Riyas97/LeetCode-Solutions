class Solution {
public:
    int minDeletions(string s) {
        map <int, int> u;
        vector <int> v2 (s.length() + 1, 0);
        vector <int> v (26, 0);
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
        }
        
        
        for (int i = 0; i <= 25; i++) {
            if (v[i] != 0) {
                cout << v[i];
                cout << v2[v[i]];
                v2[v[i]]++;
            }
        }
        
        stack <int> st;
        int keep = 0;
        
        for (int i = 1; i < v2.size(); i++) {
            if (keep == s.length()) {
                break;
            }
            if (v2[i] == 0) {
                st.push(i);
            } else if (v2[i] == 1) {
                cout << v2[i] << " ";
                keep += v2[i];
                continue;
            } else {
                keep += v2[i];
                int num = v2[i] - 1;
                
                while (!st.empty() && num > 0) {
                    int newn = st.top();
                    st.pop();
                    ans += (i - newn);
                    num--;
                }
                
                if (num != 0) {
                    // need to remove
                    ans += (num * i);
                }
                
            }
        }
        
        return ans;
    }
};