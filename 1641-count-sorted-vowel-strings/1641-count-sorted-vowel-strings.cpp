class Solution {
public:
    
    int countVowelStrings(int n) {
        if (n == 1) {
            return 5;
        }
        if (n == 2) {
            return 15;
        }
        int sum = 15;
        vector <int> v1 (5, 0);
        vector <vector<int>> v (n+1, v1);
        
        for (int j = 0; j <= 4; j++) {
            v[2][j] = 5 - j;
        }
        
        for (int i = 3; i <= n; i++) {
            v[i][0] = sum;
            for (int j = 1; j <= 4; j++) {
                v[i][j] = v[i][j-1] - v[i-1][j-1];
                sum += v[i][j];
            }
        }
        int ans = 0;
        for (int j = 0; j <= 4; j++) {
            ans += v[n][j];
        }
        return ans;
    }
};