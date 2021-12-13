class Solution {
public:
    
    void bfs(vector<string>& list, int n, map<int, string> m, string digits) {
        queue <string> q;
        q.push("");
        
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            
            if (s.length() == n) {
                list.push_back(s);
            }
            
            int count = s.length();
            
            int c = digits[count] - '0';

            string str = m[c];

            for (int j = 0; j < str.length(); j++) {
                string sn = s + str[j];
                cout << sn << " ";
                q.push(sn);
            }
            
            
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if (digits == "") {
            return ans;
        }
        
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        bfs(ans, digits.size(), m, digits);
        
        return ans;
    }
};