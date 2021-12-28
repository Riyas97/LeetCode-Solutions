class Solution {
public:
    bool canPart(vector<int>& v, vector<int>& v1) {
        for (int i = 0; i <= 25; i++) {
            if (v1[i] > 0 && v1[i] != v[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++) {
            v[s[i]-'a']++;
        }
        vector<int> v1(26, 0);
        
        int st = 0;
        
        for (int i = 0; i < s.length(); i++) {
            v1[s[i]-'a']++;
            if (canPart(v, v1)) {
                ans.push_back(i - st + 1);
                st = i + 1;
            }
        }
        return ans;
    }
};