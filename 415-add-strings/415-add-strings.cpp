class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        int carry = 0;
        
        while (i1 >= 0 && i2 >= 0) {
            int n1 = num1[i1] - '0';
            int n2 = num2[i2] - '0';
            int sum = carry + n1 + n2;
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans.push_back(c);
            i1--;
            i2--;
        }
        
        while (i1 >= 0) {
            int n1 = num1[i1] - '0';
            int sum = carry + n1;
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans.push_back(c);
            i1--;
        }
        
        while (i2 >= 0) {
            int n2 = num2[i2] - '0';
            int sum = carry + n2;
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans.push_back(c);
            i2--;
        }
        
        if (carry > 0) {
            ans.push_back('0' + carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};