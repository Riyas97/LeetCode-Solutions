class Solution {
public:
    int get(int num) {
        int a = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                a++;
            }
            num /= 2;
        }
        return a;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int v = get(i);
            ans.push_back(v);
        }
        return ans;
    }
};