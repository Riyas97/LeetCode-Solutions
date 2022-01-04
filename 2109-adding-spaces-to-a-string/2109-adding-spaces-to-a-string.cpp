class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int xtra = 0;
        int totalL = s.length() + spaces.size();
        int index = 0;
        bool noConst = false;
        for (int i = 0; i < s.length(); i++) {
            if (noConst) {
                ans += s[i];
            } else {
                if (i < spaces[index]) {
                    ans += s[i];
                } else if (i == spaces[index]) {
                    ans += " ";
                    index++;
                    if (index == spaces.size()) {
                        noConst = true;
                    }
                    ans += s[i];
                }    
            }
            
            
        }
        return ans;
        
    }
};