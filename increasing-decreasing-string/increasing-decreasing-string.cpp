class Solution {
public:
    string sortString(string s) {
        vector <int> v (26, 0);
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
        }
        
        bool isCon = true;
        bool forw = true;
        
        while (isCon) {
            isCon = false;
            if (forw) {
                forw = false;
                for (int i = 0; i < 26; i++) {
                    if (v[i] > 0) {
                        v[i] -= 1;
                        isCon = true;
                        result += (i + 'a');
                    }
                }        
            } else {
                forw = true;
                for (int i = 25; i >= 0; i--) {
                    if (v[i] > 0) {
                        v[i] -= 1;
                        isCon = true;
                        result += (i + 'a');
                    }
                } 
            }
        }
        return result;
    }
};