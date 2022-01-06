class Solution {
public:
    bool sortcol(vector<int>& v1, vector<int>& v2) {
     return v1[1] < v2[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [this] 
             (vector<int> a, vector<int> b) {
                 return sortcol(a, b); 
             }
            );
        
        priority_queue <pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>>> stop;
        int left = capacity;
        
        for (int i = 0; i < trips.size(); i++) {
            cout << "st: " << trips[i][1] << "\n";
            int num = trips[i][0];
            int st = trips[i][1];
            int en = trips[i][2];
            
            // alight
            while (!stop.empty()) {
                pair<int,int> p = stop.top();
                int stnum = get<0>(p);
                int passen = get<1>(p);
                cout << "alight: " << stnum << " " << passen << "\n";
                
                if (stnum > st) {
                    break;
                } else {
                    left += passen;
                    stop.pop();
                }
            }
            
            if (num <= left) {
                left -= num;
                stop.push(pair(en, num));
            } else {
                return false;
            }
        }
        
        return true;
    }
};