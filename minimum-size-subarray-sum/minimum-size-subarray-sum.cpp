class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st = 0;
        int en = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (en <= nums.size() - 1) {
            sum += nums[en];
            //cout << st << en << sum << "\n";
            if (sum < target) {
                en++;
            } else {
                while (sum >= target) {
                    cout << en - st + 1;
                    ans = min(ans, en - st + 1);
                    sum -= nums[st];
                    st++;
                }
                en++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
        
    }
};