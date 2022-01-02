class Solution {
public:
    bool eqDis(vector <int>& v1, vector <int>& v2) {
        int val1 = 0;
        int val2 = 0;
        for (int i = 0; i <= 25; i++) {
            if (v1[i] > 0) {
                val1++;
            }
            if (v2[i] > 0) {
                val2++;
            }
        }
        if (val1 == val2) {
            return true;
        } 
        return false;
    }
    
    int numSplits(string s) {
        vector <int> v1 (26, 0);
        for (int i = 0; i < s.length(); i++) {
            v1[s[i] - 'a']++;
        }
        vector <int> v2 (26, 0);
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            v1[s[i-1] - 'a']--;
            v2[s[i-1] - 'a']++;
            if (eqDis(v1, v2)) {
                ans++;
            }
        }
        
        return ans;
    }
};