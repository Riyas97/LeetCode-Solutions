class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int> m1;
        map <int, set<string>> m2;
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (m1[word] == 0) {
                m1[word] = 1;
                
                if (m2.find(1) == m2.end()) {
                    set<string> s1;
                    s1.insert(word);
                    m2[1] = s1;
                } else {
                    m2[1].insert(word);
                }
            } else {
                int num = m1[word];
                m1[word]++;
                
                m2[num].erase(word);
                
                num += 1;
                if (m2.find(num) == m2.end()) {
                    set<string> s1;
                    s1.insert(word);
                    m2[num] = s1;
                } else {
                    m2[num].insert(word);
                }
            }
        }
        
        vector <string> ans;
        auto it = m2.rbegin();
        
        while (true) {
            set<string> s1 = it->second;
            
            for (auto itt = s1.begin(); itt != s1.end(); itt++) {
                ans.push_back(*itt);
                k -= 1;
                
                if (k == 0) {
                    break;
                }
            }
            
            if (k == 0) {
                    break;
            }
            
            it++;
        }
        return ans;
    }
};