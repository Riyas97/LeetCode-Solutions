class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> og;
    unordered_map<string, int> summ;
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (og.count(key) == 0) {
            // new entry
            og[key] = val;
            // update the sum map
            for (int i = 1; i <= key.size(); i++) {
                string subString = key.substr(0, i);
                 
                if (summ.count(subString) == 0) {
                    summ[subString] = val; 
                } else {
                    summ[subString] += val;
                }
                //cout << subString << ": " << summ[subString] << endl;
            }
            
        } else {
            // update the sum map
            for (int i = 1; i <= key.size(); i++) {
                string subString = key.substr(0, i);
                 
                
                summ[subString] = summ[subString] - og[key] + val;
                
                //cout << subString << ": " << summ[subString] << endl;
            }
            
            // override
            og[key] = val;
            // change the sum map
            
            
        }
        
        
    }
    
    int sum(string prefix) {
        return summ[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */