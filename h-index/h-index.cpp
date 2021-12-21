class Solution {
public:
    int hIndex(vector<int>& citations) {
        map <int, int> m;
        
        for (int i = 0; i < citations.size(); i++) {
            m[citations[i]]++;
        }
        
        int maxH = 0;
        int n = citations.size();
        int h = citations.size();
        
        for (auto it = m.begin(); it != m.end(); it++) {
            int num = it->first;
            int number = it->second;
            cout << "f" << num << " " << number << "\n";
            
            while(number >= 1) {
                //cout << "bb" << number << " " << h << "\n";
                if (num >= h) {
                    maxH = max(maxH, h);
                }
                number -= 1;
                h -= 1;
            }     
        }
        return maxH;
    }
};