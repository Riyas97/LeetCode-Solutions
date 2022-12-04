class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int avg = INT_MAX;
        int ind = -1;
        long long sofar = 0;
        for (int i = 0; i < nums.size(); i++) {
            sofar += nums[i];
            int calc;
            if (i == nums.size()-1) {
                calc = (sofar / (i+1));
            } else {
                calc = (sofar / (i+1)) - (sum - sofar) / (nums.size()-i-1);
            }   
            calc = abs(calc);
            //cout << i << " " << calc << "\n";
            if (calc < avg) {
                avg = calc;
                ind = i;
            }
        }
        return ind;
    }
};