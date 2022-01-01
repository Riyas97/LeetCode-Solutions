class Solution {
public:
    int dp(int n, vector<int> & v1) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (v1[n] != 0) {
            return v1[n];
        }
        v1[n] = dp(n-1, v1) + dp(n-2, v1);
        return v1[n];
    }
    
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector <int> v1 (n, 0);
        v1[1] = 1;
        return dp(n-1, v1) + dp(n-2, v1);
    }
};