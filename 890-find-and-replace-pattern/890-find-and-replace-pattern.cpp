class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char,char> um;
            unordered_map<char,char> rev;
            string str = words[i];
            bool notA = true;
            for (int i = 0; i < str.length(); i++) {
                if (um.find(pattern[i]) == um.end()) {
                    if (rev.find(str[i]) == rev.end()) {
                        um[pattern[i]] = str[i];
                        rev[str[i]] = um[pattern[i]];
                    } else {
                        notA = false;
                        break;
                    }
                    
                } else {
                    char get = um[pattern[i]];
                    if (get != str[i]) {
                        notA = false;
                        break;
                    }
                }
            }
            
            if (notA) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};