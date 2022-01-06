class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int ind1 = a.length() - 1;
        int ind2 = b.length() - 1;
        int carry = 0;
        
        while (ind1 >= 0 && ind2 >= 0) {
            int n1 = a[ind1] - '0';
            int n2 = b[ind2] - '0';
            int sum = carry + n1 + n2;
            carry = sum / 2;
            char c = '0' + (sum % 2);
            ans.push_back(c);
            ind1--;
            ind2--;
        }
        
        while (ind1 >= 0) {
            int n1 = a[ind1] - '0';
            int sum = carry + n1;
            carry = sum / 2;
            char c = '0' + (sum % 2);
            ans.push_back(c);
            ind1--;
        }
        
        while (ind2 >= 0) {
            int n2 = b[ind2] - '0';
            int sum = carry + n2;
            carry = sum / 2;
            char c = '0' + (sum % 2);
            ans.push_back(c);
            ind2--;
        }
        
        if (carry > 0) {
            char c = '0' + carry;
            ans.push_back(c);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};