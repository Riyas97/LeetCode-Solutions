class Solution {
public:
    int dp(vector<int>& nums, vector<int>& seq,
           int ind) {
    
        if (seq[ind] != 0) {
            return seq[ind];
        }
        
        int nu = 1;
        for (int i = ind - 1; i >= 0; i--) {
            if (nums[i] < nums[ind]) {
                int sqlen = dp(nums, seq, i);
                //cout << i << ind << " " << sqlen + 1 << "\n";
                nu = max(nu, sqlen + 1);
            } 
        }
        seq[ind] = nu;
        return seq[ind];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector <int> seq (nums.size(), 0);
        seq[0] = 1;
        int mnum = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int sqlen = dp(nums, seq, i);
            cout << i << " " << sqlen << "\n";
            mnum = max(mnum, sqlen);
        }
        return mnum;
    }
};