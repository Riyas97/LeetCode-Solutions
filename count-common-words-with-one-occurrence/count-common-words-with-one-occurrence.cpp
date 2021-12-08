class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_set <string> s1;
        unordered_set <string> s11; // repeated
        unordered_set <string> s2;
        unordered_set <string> ans;
        
        for (int i = 0; i < words1.size(); i++) {
            if (s1.find(words1[i]) == s1.end()) {
                s1.insert(words1[i]);
            } else {
                s11.insert(words1[i]);
            }
        }
        
        for (int i = 0; i < words2.size(); i++) {
            if (s2.find(words2[i]) == s2.end()) {
                s2.insert(words2[i]);
                
                if (s1.find(words2[i]) != s1.end() && s11.find(words2[i]) == s11.end()) {
                    ans.insert(words2[i]);
                } 
            } else {
                if (ans.find(words2[i]) != ans.end()) {
                    ans.erase(words2[i]);
                }
            }
        }
        return ans.size();
    }
};