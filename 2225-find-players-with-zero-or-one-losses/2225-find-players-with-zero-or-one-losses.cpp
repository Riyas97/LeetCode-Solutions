class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> count; 
        
        for (int i = 0; i < matches.size(); i++) {
            int w = matches[i][0];
            int l = matches[i][1];
            
            if (count.find(w) == count.end()) {
                count[w] = 0;
            }
            if (count.find(l) == count.end()) {
                count[l] = 1;
            } else {
                count[l]++;
            }
        }
        vector<int> wonAll;
        vector<int> lostOnce;
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second == 0) {
                wonAll.push_back(it->first);
            } else if (it->second == 1) {
                lostOnce.push_back(it->first);
            } 
        }
        
        return {wonAll, lostOnce};
    }
};