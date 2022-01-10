class Trie {
public:
    unordered_set <string> wo;
    unordered_set <string> prefix;
    
    Trie() {
        
    }
    
    void insert(string word) {
        wo.insert(word);
        if (prefix.find(word) == prefix.end()) {
            int len = word.length();
            while(len) {
                string w1 = word.substr(0, len);
                if (prefix.find(w1) == prefix.end()) {
                    prefix.insert(w1);
                } else {
                    break;
                }
                len--;
            }
        }
    }
    
    bool search(string word) {
        if (wo.find(word) == wo.end()) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefi) {
        if (prefix.find(prefi) == prefix.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */