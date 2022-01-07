class Solution {
public:
    
    map<int, int> m;
    
    int climbStairs(int n) {
        if (m[n]) {
            cout << n << "\n";
            return m[n];
        }
        
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        m[n] = climbStairs(n-1) + climbStairs(n-2);
        return m[n];
    }
};