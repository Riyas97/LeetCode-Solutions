class Solution {
public:
    int find(int s, int e, vector<int>& nums) {
        
        if (s < e) {
            int m = (s + e) / 2;
        
            
            if ((m != 0 && nums[m-1] == nums[m]) || 
                ((m != nums.size() - 1) && nums[m] == nums[m+1])) {
                return nums[m];
            }
            int a = find(s, m-1, nums);
            int b = find(m+1, e, nums);
            
            if (a != -1) {
                return a;
            }
            if (b != -1) {
                return b;
            }
            return -1;
        }
        return -1;
    }
    
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int s = 0;
        int e = nums.size() - 1;
        
        int ans = find(s, e, nums);
        
        return ans;
    }
};