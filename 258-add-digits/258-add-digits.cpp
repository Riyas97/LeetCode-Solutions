class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        if (num % 9 == 0) {
            return 9;
        }
        return num % 9;
        /*
        if (num < 10) {
            return num;
        }
        while (num >= 10) {
            int num1 = 0;
            while (num > 0) {
                int d = num % 10;
                num /= 10;
                num1 += d;
            }
            num = num1;
        }
        return num;
        */
    }
};