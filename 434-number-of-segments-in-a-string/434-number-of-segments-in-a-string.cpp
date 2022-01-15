class Solution {
public:
    int countSegments(string s) {
        int seg = 0;
        bool wo = false;
        for (int i = 0; i < s.length(); i++) {
            if (isspace(s[i])) {
                if (wo) {
                    seg++;
                    wo = false;
                }
            } else {
                wo = true;
            } 
        }
        if (wo) {
            seg++;
        }
        return seg;
    }
};