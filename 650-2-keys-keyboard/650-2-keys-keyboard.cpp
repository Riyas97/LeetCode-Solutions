class Solution {
public:
    int fac(int n) {
        int ans = -1;
        int s = sqrt(n);
        for (int i = 2; i <= s; i++) {
            if (n % i == 0) {
                return i;
            }
        }
        return ans;
    }
    
    int minSteps(int n) {
        int ans = 0;
        if (n == 1) {
            return 0;
        }
        while (n > 0) {
            int f = fac(n);
            if (f == -1) {
                // prime
                ans += n;
                break;
            } else {
                ans += f;
                n /= f;
            }
        }
        return ans;
    }
};