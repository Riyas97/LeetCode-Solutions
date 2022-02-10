class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> letts {'a', 'e', 'i', 'o', 'u'};
        bool start = true;
        int ind = 0;
        int ans = 0;
        char next = 0;
        int stindex = -1;
        
        while (ind < word.length()) {
            if (start) {
                while (ind < word.length() && 
                       word[ind] != letts[next]) {
                    ind++;
                }
                start = false;
                stindex = ind;
                while (ind < word.length() && 
                       word[ind] == letts[next]) {
                    ind++;
                }
                next += 1;
            } else {
                if (word[ind] == letts[next]) {
                    while (ind < word.length() && 
                           word[ind] == letts[next]) {
                        ind++;
                    }
                    next += 1;
                    if (next == 5) {
                        ans = max(ans, ind - stindex);
                        next = 0;
                        start = true;
                    }
                } else {
                    next = 0;
                    start = true;
                }
            }
        }
        return ans;
    }
};