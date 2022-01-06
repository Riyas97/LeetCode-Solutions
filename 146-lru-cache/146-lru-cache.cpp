class LRUCache {
public:
    unordered_map <int, int> um;
    int cap = -1;
    int time = 1;
    int mtime = 1;
    // time to key
    unordered_map <int, int> t1;
    // key to last used time
    unordered_map <int, int> t2;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) {
            return -1;
        }
        int val = t2[key];
        t1.erase(val);
        t1[time] = key;
        t2[key] = time;
        
        time++;
        return um[key];
    }
    
    void put(int key, int value) {
        if (um.find(key) == um.end()) {
            if (um.size() < cap) {
                um[key] = value;
                t1[time] = key;
                t2[key] = time;
            } else {
                //remove first
                while (mtime < time) {
                    if (t1.find(mtime) == t1.end()) {
                        mtime++;
                    } else {
                        if (um.find(t1[mtime]) == 
                           um.end()) {
                            t1.erase(mtime);
                            mtime++;
                        } else {
                            int ele = t1[mtime];
                            um.erase(ele);
                            t1.erase(mtime);
                            t2.erase(ele);
                            mtime++;
                            break;
                        }
                    }
                }
                
                // add
                um[key] = value;
                t1[time] = key;
                t2[key] = time;
            }
        } else {
            um[key] = value;
            int val = t2[key];
            t1.erase(val);
            t1[time] = key;
            t2[key] = time;
        }
        time++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */