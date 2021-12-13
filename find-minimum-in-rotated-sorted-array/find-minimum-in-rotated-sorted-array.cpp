class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        int m = (s + e) / 2;
        int a = nums[m];
        
        while (s <= e) {
            int m = (s + e) / 2;
            
            if (nums[m] < a) {
                a = nums[m];
            }
                
            if (m == s) {
                s = m + 1;
                continue;
            }
            
            
            bool q = nums[s] < nums[m];
            bool r = nums[m] < nums[e];
            
            if (nums[m-1] > nums[m] && nums[m] < nums[m+1]) {
                return nums[m];
            }
            
            if (q && r) {
                return nums[s];
            }
            
            if (q && !r) {
                s = m + 1;
            }
            
            if (r && !q) {
                e = m - 1;
            }
            
            
            
        }
        return a;
        
    }
};