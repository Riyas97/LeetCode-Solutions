class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            string str2 = str;
            reverse(str2.begin(), str2.end());
            if (str == str2) {
                return str;
            }
        }
        return "";
    }
};