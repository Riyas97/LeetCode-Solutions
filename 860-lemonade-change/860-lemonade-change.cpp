class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int amt5 = 0;
        int amt10 = 0;
        int amt20 = 0;
        for (int i = 0; i < bills.size(); i++) {
            //cout << amt << " ";
            if (bills[i] == 5) {
                amt5 += 1;
            } else if (bills[i] == 10) {
                if (amt5 == 0) {
                    return false;
                }
                amt5 -= 1;
                amt10++;
            } else {
                if (amt10 > 0 && amt5 > 0) {
                    amt10--;
                    amt5--;
                    amt20++;
                } else if (amt5 >= 3) {
                    amt5 -= 3;
                    amt20++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};