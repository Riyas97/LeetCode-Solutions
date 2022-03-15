class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int openBracks = 0; 
        int closeBracks = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openBracks++;
            } else if (s[i] == ')') {
                closeBracks++;
            }
        }
        string ans = "";
        int currOpen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (currOpen < closeBracks) {
                    currOpen++;
                    ans.push_back(s[i]);
                } else {
                    continue;
                }
            } else if (s[i] == ')') {
                if (currOpen > 0) {
                    currOpen--;
                    ans.push_back(s[i]);
                }
                closeBracks--;
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};