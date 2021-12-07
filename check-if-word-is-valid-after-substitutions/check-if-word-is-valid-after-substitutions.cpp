class Solution {
public:
    bool isValid(string s) {
        stack <char> a;
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == 'a') {
                a.push(s[i]);
            } else if (s[i] == 'b') {
                if (a.empty()) {
                    return false;
                }
                a.push(s[i]);
            } else if (s[i] == 'c') {
                if (a.empty()) {
                    return false;
                }
                char first = a.top();
                a.pop();
                if (a.empty()) {
                    return false;
                }
                char second = a.top();
                a.pop();
                if (first != 'b' || second != 'a') {
                    return false;
                } 
            }
        }
        if (a.empty()) {
            return true;
        }
        return false;
        
    }
};