class Solution {
public:
    /*
    Workings:
    6
    (6-3+1) + (6-4+1)
    */
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int ans = 0;
        int diff = nums[1] - nums[0];
        int st = 0;
        int eles = 1;
        for (int i = 1; i < nums.size(); i++) {
            int d = nums[i] - nums[i-1];
            if (d == diff) {
                eles++;
            } else {
                int size = i - st;
                if (size >= 3) {
                    int size = i - st;
                    int first = size - 3 + 1;
                    int last = 1;
                    int sum = ((first - last + 1) * 
                               (first + last) / 2); 
                    //cout << "n" << st << " " << first << " " 
                    //    << last << " " << sum << "\n";
                    ans += sum;
                }
                diff = d;
                st = i - 1;
                eles = 2;
            }
        }
        
        if (eles >= 3) {
            int size = nums.size() - st;
            int first = size - 3 + 1;
            int last = 1;
            int sum = ((first - last + 1) * (first + last)
                   / 2); 
            //cout << st << " " << first << " " << last << 
            //    " " << sum << "\n";
            
            ans += sum;
        }
        
        
        
        return ans;
    }
};