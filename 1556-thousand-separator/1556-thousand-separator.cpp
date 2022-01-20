class Solution {
public:
    string thousandSeparator(int n) {
        string ans = "";
        int count = 0;
        if (n == 0) {
            ans += '0';
            return ans;
        }
        while (n > 0) {
            if (count == 3) {
                ans = '.' + ans;
                count = 0;
            }
            int d = n % 10;
            n /= 10;
            char lett = d + '0';
            count++;
            ans = lett + ans;
        }
        return ans;
    }
};