class RandomizedSet {
public:
    unordered_set <int> us;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (us.find(val) != us.end()) {
            return false;
        }
        us.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (us.find(val) != us.end()) {
            us.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random = (rand() % us.size());
        auto it = us.begin();
        while(random--) {
            it++;
        }
        //it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */