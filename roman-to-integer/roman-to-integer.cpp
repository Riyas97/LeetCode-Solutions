class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == 'I') {
                ans += 1;
            } else if (s[i] == 'V') {
                if (i != 0 && s[i - 1] == 'I') {
                    ans -= 2;
                    ans += 5;
                } else {
                    ans += 5;
                }
            } else if (s[i] == 'X') {
                if (i != 0 && s[i - 1] == 'I') {
                    ans -= 2;
                    ans += 10;
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'L') {
                if (i != 0 && s[i - 1] == 'X') {
                    ans -= 20;
                    ans += 50;
                } else {
                    ans += 50;
                }
            } else if (s[i] == 'C') {
                if (i != 0 && s[i - 1] == 'X') {
                    ans -= 20;
                    ans += 100;
                } else {
                    ans += 100;
                }
            } else if (s[i] == 'D') {
                if (i != 0 && s[i - 1] == 'C') {
                    ans -= 200;
                    ans += 500;
                } else {
                    ans += 500;
                }
            } else if (s[i] == 'M') {
                if (i != 0 && s[i - 1] == 'C') {
                    ans -= 200;
                    ans += 1000;
                } else {
                    ans += 1000;
                }
            }

        }
        return ans;
    }
};