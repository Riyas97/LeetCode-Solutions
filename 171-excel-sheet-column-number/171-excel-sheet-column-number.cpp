class Solution {
public:
    /*
    A
    AA, AB, AC, ..
    AAA, AAB, .. , ABA, ABB
    */
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int round = 0;
        for (int i = columnTitle.length()-1; i>=0; i--) {
            int n = ((columnTitle[i] - 'A') % 26) + 1;
            if (round == 0) {
                ans += n;
            } else {
                ans += pow(26, round) * n;
            }
            round++;
        }
        return ans;
    }
};