class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> vals(nums.size(), 0);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            vals[i] = sum;
        }
        int avg = INT_MAX;
        int ind = -1;
        for (int i = 0; i < nums.size(); i++) {
            int calc;
            if (i == nums.size()-1) {
                calc = (vals[i] / (i+1));
            } else {
                calc = (vals[i] / (i+1)) - (vals[nums.size()-1] - vals[i]) / (nums.size()-i-1);
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