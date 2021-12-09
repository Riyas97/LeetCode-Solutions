class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        map <int, int> m;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (m.find(boxTypes[i][1]) == m.end()) {
                m[boxTypes[i][1]] = boxTypes[i][0];    
            } else {
                m[boxTypes[i][1]] += boxTypes[i][0];
            }
            
        }
        
        int ab = 0;
        int au = 0;
        for (auto i = m.rbegin(); i != m.rend(); ++i) {
            int u = i->first;
            int b = i->second;
            if (ab + b > truckSize) {
                au += (truckSize - ab) * u;
                break;
            }
            ab += b;
            au += (b) * u;
            
            if (ab == truckSize) {
                break;
            }
        }
        return au;             
    }
};