class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] <= 8) {
            digits[digits.size() - 1] += 1;
            return digits;
        }
        
        int c = digits.size() - 1;
        
        while (c >= 0 && digits[c] == 9) {
            c -= 1; 
        }
        
        int totalL = digits.size();
        
        if (c < 0) {
            totalL += 1;
        }
        
        vector <int> ans (totalL, 0);
        ans[0] = 1;
        
        for (int i = 0; i <= c; i++) {
            ans[i] = digits[i];
            
            if (i == c) {
                ans[i] += 1;
            }
        }
        
        return ans;
    }
};