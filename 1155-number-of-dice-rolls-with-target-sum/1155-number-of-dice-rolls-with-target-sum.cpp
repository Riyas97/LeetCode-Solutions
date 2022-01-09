class Solution {
public:
    void dp(int n, int k, int target, int& ans, int sum,
            unordered_map <int, unordered_map<int, int>>& um) {
        
        if (sum == target) {
            if (n == 0) {
                ans %= 1000000007;
                ans++;
                return;
            } else {
                return;
            }
        }
        
        if (sum > target) {
            return;
        }
        
        if (n <= 0) {
            return;
        }
        
        if (um.find(n) != um.end() &&
            um[n].find(sum) != um[n].end()) {
            //cout << "yes";
            ans %= 1000000007;
            ans += um[n][sum];
            return;
        }
        
        ans %= 1000000007;
        int prev = ans;
        
        for (int i = 1; i <= k; i++) {
            sum += i;
            //cout << n << " " << sum << " " << i << " " << ans << "\n";
            dp(n-1, k, target, ans, sum, um);
            //cout << n << " " << sum << " " << i << " " << ans << "\n";
            sum -= i;
        }
        
        int val = ans - prev;
        
        if (val < 0) {
            //cout << "yes";
            val = 1000000007 - prev + ans;
        }
        
        val %= 1000000007;
        um[n][sum] = val;
        //cout << n << " " << sum << " " << ans << "\n";
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        if (n == 1) {
            if (target <= k) {
                return 1;
            } else {
                return 0;
            }
        }
        
        unordered_map <int, unordered_map<int, int>> um;
        
        int ans = 0;
        int sum = 0;
        //int count = 0;
        dp(n, k, target, ans, sum, um);
        
        //cout << um[n][0];
        return (int) ans % 1000000007;
    }
};