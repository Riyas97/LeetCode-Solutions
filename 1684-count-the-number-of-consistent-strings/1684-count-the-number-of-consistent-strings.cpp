class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> v(26, 0);
        
        for (int i = 0; i < allowed.size(); i++) {
            v[allowed[i] - 'a']++;
        }
        
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            bool isOk = true;
            for (int j = 0; j < str.length(); j++) {
                if (v[str[j] - 'a'] == 0) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                ans++;
            }
        }
        return ans;
        
    }
};