class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n1 = num.size() - 1;
        int carry = 0;
        
        while (n1 >= 0 && k > 0) {
            int a1 = k % 10;
            int sum = carry + num[n1] + a1;
            carry = sum / 10;
            ans.push_back(sum % 10);
            n1--;
            k /= 10;
        }
        
        while (n1 >= 0) {
            int sum = carry + num[n1];
            carry = sum / 10;
            ans.push_back(sum % 10);
            n1--;
        }
        
        while (k > 0) {
            int a1 = k % 10;
            int sum = carry + a1;
            carry = sum / 10;
            ans.push_back(sum % 10);
            k /= 10;
        }
        
        if (carry > 0) {
            ans.push_back(carry);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};