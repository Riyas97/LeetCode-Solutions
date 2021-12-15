class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        unordered_map <string, int> u;
        vector <int> v1 (26, 0);
        
        for (int j = 0; j < words[0].length(); j++) {
            v1[words[0][j] - 'a'] += 1;
            
            string ch;
            ch.push_back(words[0][j]);
            if (u.find(ch) == u.end()) {
                u[ch] = 1;
            } else {
                while (u.find(ch) != u.end()) {
                    ch += words[0][j];
                }
                u[ch] = 1;
            }
        }
        
        for (int i = 1; i < words.size(); i++) {
            vector <int> v2 (26, 0);
            for (int j = 0; j < words[i].length(); j++) {
                v2[words[i][j] - 'a'] += 1;
                string ch;
                ch.push_back(words[i][j]);
                if (u.find(ch) == u.end()) {
                    continue;
                } else {
                    while (u.find(ch) != u.end() && u[ch] == i + 1) {
                        ch += words[i][j];
                    }
                    if (u.find(ch) != u.end()) {
                        u[ch] += 1;    
                    }
                    
                }
            }
            
            //cout << v1[0] << v2[0] << "\n";
            
            for (int j = 0; j <= 25; j++) {
                if (v1[j] > v2[j]) {
                    int diff = v1[j] - v2[j];
                    string ch;
                    int count = 0;
                    while (count <= v2[j]) {
                        ch.push_back(j + 'a');
                        count += 1;
                    }
                    while (count <= v1[j]) {
                        u.erase(ch);
                        cout << i << "remove " << ch << "\n";
                        count += 1;
                        ch.push_back(j + 'a');
                    }
                        
                    v1[j] = v2[j];
                }
            }
        }
        
        vector<string> ans;
        
        for (auto it = u.begin(); it != u.end(); it++) {
            cout << it->first << " " << it->second << "\n";
            int no = it->second;
            if (no == words.size()) {
                string dd = it->first;
                if (dd.length() > 1) {
                    ans.push_back(std::string(1, dd[0]));
                } else {
                    ans.push_back(dd);    
                }
                
            }
        }
        return ans;
        
    }
};