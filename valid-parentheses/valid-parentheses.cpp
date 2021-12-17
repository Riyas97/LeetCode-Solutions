class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == ')') {
                if (stack.empty()) {
                    return false;
                }
                char a = stack.top();
                stack.pop();
                if (a != '(') {
                    return false;
                } 
            }
            else if (s[i] == '}') {
                if (stack.empty()) {
                    return false;
                }
                char a = stack.top();
                stack.pop();
                if (a != '{') {
                    return false;
                } 
            }
            else if (s[i] == ']') {
                if (stack.empty()) {
                    return false;
                }
                char a = stack.top();
                stack.pop();
                if (a != '[') {
                    return false;
                } 
            }
            else {
                stack.push(s[i]);
            }
            
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }
};