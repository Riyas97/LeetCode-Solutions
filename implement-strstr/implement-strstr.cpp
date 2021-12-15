class Solution {
public:
    int strStr(string h, string n) {
        int a = -1;
        if (n.size() == 0) {
            return 0;
        }
        if (h.size() == 0) {
            return a;
        }
        if (h.size() < n.size()) {
            return -1;
        }
        if (h.size() == n.size() && h == n) {
            return 0;
        } else if (h.size() == n.size() && h != n) {
            return -1;
        } 
        
        for (int i = 0; i <= h.size() - n.size(); i++) {
            string str = h.substr(i, n.size());
            if (str == n) {
                return i;
            }
        }
        return -1;
    }
};

/*
int a = 0;
        int occ = -1;
        bool ish = false;
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() == 0) {
            return occ;
        }
        for (int i = 0; i < haystack.size(); i++) {
            if (ish && haystack[i] == needle[a]) {
                a += 1;
            } else if (ish && haystack[i] != needle[a]) {
                a = 0;
                ish = false;
                occ = -1;
            } else if (!ish && haystack[i] == needle[a]) {
                ish = true;
                a += 1;
                occ = i;
            }
            if (a == needle.size()) {
                return occ;
            }
        }
        return -1;
*/