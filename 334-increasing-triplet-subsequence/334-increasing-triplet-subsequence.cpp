class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int a1 = nums[0];
        int a2 = nums[0];
        bool hasa2 = false;
        bool hasalreadytwo = false;
        int minof = -1;
        
        for (int i = 1; i < nums.size(); i++) {
           // cout << a1 << " " << hasa2 << " " << a2 << " " << 
           //     nums[i] << "\n";
            
            if (hasalreadytwo && nums[i] > minof) {
                return true;
            }
            
            if (nums[i] < a1) {
                if (hasa2) {
                    minof = a2;
                    hasalreadytwo = true;
                    hasa2 = false;
                }
                a1 = nums[i];
                
            } else if (nums[i] == a1) {
                continue;
            
            } else if (nums[i] > a1) {
                if (!hasa2) {
                    a2 = nums[i];
                    hasa2 = true;
                } else {
                    if (nums[i] > a2) {
                        return true;
                    } else {
                        a2 = nums[i];
                    }
                }
            }
        }
        return false;
    }
};