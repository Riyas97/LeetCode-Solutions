class Solution {
public:
    string generateTheString(int n) {
      
        string ans = "";
        
        if (n % 2 != 0) {
            //odd
            for (int i = 0; i < n; i++) {
                ans.push_back('a');
            }
        } else {
            // even
            for (int i = 0; i < n - 1; i++) {
                ans.push_back('a');
            }
            ans.push_back('b');
        }
        return ans;
    }
};