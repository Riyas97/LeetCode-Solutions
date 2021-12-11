class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> u;
        queue <char> st;
        int a = 0;
        for (int i = 0; i < s.length(); i++) {
            if (u.find(s[i]) == u.end()) {
                u.insert(s[i]);
                st.push(s[i]);
                cout << "add" << s[i] << "\n";
            } else {
                cout << i << "\n";
                //cout << st.top();
                
                while (st.front() != s[i]) {
                    char c = st.front();
                    st.pop();
                    cout << "re" << c << "\n";
                    u.erase(c);
                }
                
                st.pop();
                st.push(s[i]);
            }
            int n = st.size();
            if (n > a) {
                a = n;
                //cout << i << a << " ";
            }
        }
        return a;
    }
};