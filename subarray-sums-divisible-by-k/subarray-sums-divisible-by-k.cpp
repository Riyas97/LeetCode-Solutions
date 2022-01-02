class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> u;
        int ans = 0;
        int sum = 0;
        
        //cout << (-7 % 5 + 5) % 5;
        //cout << (7 % 5 + 5) % 5;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum % k == 0) {
                ans += 1;
            }
            int remain = (sum % k + k) % k;
            cout << sum << remain << " ";
            ans += u[remain];
            u[remain]++;
        }
        return ans;
    }
};