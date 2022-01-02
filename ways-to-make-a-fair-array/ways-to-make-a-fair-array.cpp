class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int osum = 0;
        int esum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                osum += nums[i];
            } else {
                esum += nums[i];
            }
        }
        int ost = 0;
        int est = 0;
        
        int ways = 0;
        for (int i = 0; i < nums.size(); i++) {
            int select = nums[i];
            if (i % 2 == 0) {
                // odd
                int posum = ost;
                int pesum = est;
                int fosum = esum - est;
                int fesum = osum - nums[i] - ost;
                
                int nosum = posum + fosum;
                int nesum = pesum + fesum;
                if (nosum == nesum) {
                    ways += 1;
                }
                ost += nums[i];
            } else {
                // even
                int posum = ost;
                int pesum = est;
                int fosum = esum - nums[i] - est;
                int fesum = osum - ost;
                
                int nosum = posum + fosum;
                int nesum = pesum + fesum;
                if (nosum == nesum) {
                    ways += 1;
                }
                est += nums[i];
            }
        }
        return ways;
    }
};