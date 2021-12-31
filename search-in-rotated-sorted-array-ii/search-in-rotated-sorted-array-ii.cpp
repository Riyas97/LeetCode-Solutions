class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                return true;
            }
            if (nums[s] < nums[m]) {
                // sorted
                if (target < nums[m] && target >= nums[s]) {
                    e = m - 1;
                } else {
                    // t is bigger than nums[m]
                    // or t is smaller than nums[m]  
                    // but smaller than nums[s]
                    s = m + 1;
                }
            } else if (nums[s] == nums[m]) {
                   s++; 
            
            } else {
                if (target < nums[m]) {
                    e = m - 1;
                    
                } else {
                    if (target >= nums[s]) {
                        e = m - 1;
                    } else {
                        s = m + 1;
                    }
                }
            }
        }
        return false;
    }
};