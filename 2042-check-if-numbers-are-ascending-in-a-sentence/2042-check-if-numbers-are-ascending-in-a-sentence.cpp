class Solution {
public:
    bool areNumbersAscending(string s) {
        bool first = true;
        int prev = 0;
        string num = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                num.push_back(s[i]);
            } else {
                if (num != "") {
                    int number = stoi(num);
                    num = "";
                    if (first) {
                        prev = number;
                        first = false;
                    } else {
                        if (number > prev) {
                            prev = number;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        
        if (num != "") {
            int number = stoi(num);
            num = "";
            if (first) {
                prev = number;
                first = false;
            } else {
                if (number > prev) {
                    prev = number;
                } else {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};