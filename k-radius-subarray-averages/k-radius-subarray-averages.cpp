class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int st = 0;
        int en = st + k + k;
        vector <int> ans (nums.size(), -1);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (i == en) {
                //cout << sum << (en - st + 1) << " ";
                //cout << (int)sum / (en - st + 1) << " ";
                ans[i-k] = sum / (en - st + 1);
                sum -= nums[st];
                st++;
                en++;
            }
        }
        return ans;
    }
};