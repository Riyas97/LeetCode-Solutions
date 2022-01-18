class Solution {
public:
    int reverse(int num) {
        int c = -1;
        vector<int> vect;
        while(num > 0) {
            int d = num % 10;
            vect.push_back(d);
            c++;
            num /= 10;
        }
        int ans = 0;
        for (int i = 0; i < vect.size(); i++) {
            ans += (vect[i] * pow(10, c));
            c--;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map <int, int> um;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]);
            //cout << rev << " ";
            ans += um[nums[i] - rev];
            ans %= 1000000007;
            um[nums[i] - rev]++;
        }
        return ans;
    }
};