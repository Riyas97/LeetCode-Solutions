class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        
        if (x == INT_MIN) {
            return 0;
        }
        
        if (x < 0) {
            x *= -1;
            isNegative = true;
        }
        int ans = 0;
        int count = -1;
        vector <int> v;
        
        while (x > 0) {
            int a = x % 10;
            v.push_back(a);
            count += 1;
            x /= 10;
            
        }
        
        for (int i = 0; i < v.size(); i++) {
            if (ans + v[i] * pow(10, count) < INT_MIN) {
                return 0;
            }
            if (ans + v[i] * pow(10, count) > INT_MAX) {
                return 0;
            }
            
            ans += (v[i] * pow(10, count));
            count -= 1;
        }
        
        if (isNegative) {
            ans *= -1;
        }
        
        return ans;
    }
};