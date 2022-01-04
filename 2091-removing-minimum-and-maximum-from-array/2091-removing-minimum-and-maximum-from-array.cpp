class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minind = -1;
        int maxind = -1;
        int minnum = INT_MAX;
        int maxnum = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minnum) {
                minnum = nums[i];
                minind = i;
            } 
            if (nums[i] > maxnum) {
                maxnum = nums[i];
                maxind = i;
            }
        }
        
        int leftmost = min(minind, maxind);
        int rightmost = max(minind, maxind);
        
        int a = rightmost + 1;
        int b = nums.size() - leftmost;
        int c = leftmost + 1 + (nums.size() - rightmost);
        
        return min({a,b,c});
    }
};