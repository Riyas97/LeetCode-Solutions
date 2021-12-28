class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string str = "";
        for (int i = 0; i < s.length(); i++) {
           if (isspace(s[i])) {
               //space
               if (str != "") {
                   if (ans == "") {
                       ans = str;
                   } else {
                       ans = str + " " + ans;   
                   }
                   str = "";
               }
           } else {
               str.push_back(s[i]);
           }
        }
        
        if (str != "") {
           if (ans == "") {
               ans = str;
           } else {
               ans = str + " " + ans;   
           }
        }
        return ans;
    }
};