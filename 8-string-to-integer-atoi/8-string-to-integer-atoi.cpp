class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        
        
        string num = "";
        bool atstart = true;
        int sign = 1;
        bool canread = false;
        
        for (int i = 0; i < s.length(); i++) {
            if (atstart && isspace(s[i])) {
                continue;
            } else if (!atstart && isspace(s[i])) {
                break;
            } else if (!isspace(s[i])) {
                if (atstart) {
                    atstart = false;
                    if (s[i] == '-') {
                        sign = -1;
                    } else if (s[i] == '+') {
                        sign = 1;
                    } else if (s[i] - '0' >= 0 &&
                              s[i] - '0' <= 9) {
                        if (s[i] != '0') {
                            num.push_back(s[i]);
                            canread = true;
                        }
                    } else {
                        //non-digit
                        break;
                    }
                } else if (s[i] - '0' >= 0 &&
                           s[i] - '0' <= 9) {
                    if (canread || s[i] != '0') {
                        num.push_back(s[i]);
                        canread = true;
                    }
                } else {
                    break;
                }
                    
            }
        }
        if (num == "") {
            return 0;
        } else {
            if (num.length() > 10) {
                if (sign == -1) {
                    ans = INT_MIN;
                } else {
                    ans = INT_MAX;
                }
            } else {
                long number = stol(num);
                number *= sign;

                if (number < INT_MIN) {
                    ans = INT_MIN;
                } else if (number > INT_MAX) {
                    ans = INT_MAX;
                } else {
                    ans = (int) number;
                }                
            }
        }
        
        return ans;
    }
};