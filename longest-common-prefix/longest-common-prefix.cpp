class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> m;
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 1; j <= strs[i].length(); j++) {
                string token = strs[i].substr(0, j);
                if (m.find(token) == m.end() && i == 0) {
                    m[token] = 1;
                } else {
                    m[token] += 1;
                }
            }
        }
        for (auto i = m.rbegin(); i != m.rend(); ++i) {
            int curr = i->second;
            if (curr == strs.size()) {
                return i->first;
            }
        }
        return "";
            
        
    }
    
    
};