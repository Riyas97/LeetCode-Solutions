class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int f1 = nums[i] - a;
            int f2 = a + nums[i];
            
            int h1 = nums[i] - c;
            int h2 = c + nums[i];
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] >= f1 && nums[j] <= f2) {
                    int g1 = nums[j] - b;
                    int g2 = b + nums[j];
                    
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (nums[k] >= h1 && nums[k] <= h2 && 
                           nums[k] >= g1 && nums[k] <= g2) {
                            ans += 1;
                        } else {
                            continue;
                        }
                    }
                } else {
                    continue;
                }
            }
        }
        return ans;
    }
};