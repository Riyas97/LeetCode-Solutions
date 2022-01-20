class Solution {
public:
    // rdrrddd  r: 3 d : 3+ 3
    string predictPartyVictory(string senate) {
        queue <int> d;
        queue <int> r;
        
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);            
            }
        }
        
        while (!d.empty() && !r.empty()) {
            int d1 = d.front();
            d.pop();
            int r1 = r.front();
            r.pop();
            if (d1 < r1) {
                d.push(d1 + senate.size());
            } else {
                r.push(r1 + senate.size());
            }
        }
        
        if (!d.empty()) {
            return "Dire";
        }
        return "Radiant";
    }
};