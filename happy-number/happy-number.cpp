class Solution {
public:
    bool check(int n, unordered_set <int> set) {
        int sum = 0;
        while (n > 0) {
            int a = n % 10;
            n /= 10;
            sum += (a * a);
        }
        if (sum == 1) {
            return true;
        } else {
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
                return check(sum, set);
            }
        }
    }
    
    bool isHappy(int n) {
        unordered_set <int> set;
        set.insert(n);
        return (check(n, set));
    }
};