class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> us;
        int ans = 0;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            s += nums[i];
            if (s == k) {
                ans += 1;
            } 
            int a = s - k;
            cout << a << " ";
            if (us.find(a) != us.end()) {
                cout << a;
                cout << s;
                ans += us[a];
            }
            
            if (us.find(s) == us.end()) {
                us[s] = 1;
            } else {
                us[s] += 1;
            }
        }
        return ans;
    }
};