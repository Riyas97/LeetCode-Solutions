class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(101, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
        }
        
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            //cout << i;
            if (v[i] > 1) {
                int val = (((v[i] - 1) * v[i]) / 2);
                //cout << val;
                ans += val;    
            }
            
        }
        return ans;
    }
};