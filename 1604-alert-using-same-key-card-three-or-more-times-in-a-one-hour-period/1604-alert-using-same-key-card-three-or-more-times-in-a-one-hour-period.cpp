class Solution {
public:
    int time(string s) {
        int t = (s[0] - '0') * 1000 + (s[1] - '0') * 100 +
            (s[3] - '0') * 10 + (s[4] - '0');
        return t;
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, set<int>> m;
        for (int i = 0; i < keyName.size(); i++) {
            if (m.find(keyName[i]) == m.end()) {
                set<int> s;
                s.insert(time(keyTime[i]));
                m[keyName[i]] = s;
            } else {
                m[keyName[i]].insert(time(keyTime[i]));
            }
        }
        
        vector<string> ans;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            string name = it->first;
            //cout << name << " here\n";
            //map<int,int> count;
            //int keep = -1;
            int count = 0;
            for (auto it2 = it->second.begin();
                it2 != it->second.end(); it2++) {
                //cout << *it2 << "\n";
                if (count <= it->second.size() - 3) {
                    int n1 = *it2;
                    auto it3 = next(it2, 2);
                    int n2 = *it3;
                    //cout << n2 << "\n";
                    if (n2 - n1 <= 100) {
                        ans.push_back(name);
                        break;
                    }
                    count++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};