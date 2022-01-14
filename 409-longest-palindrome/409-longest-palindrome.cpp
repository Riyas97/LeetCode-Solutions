class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <int, int> cnt;
        unordered_map <char, int> freq;
        
        for (int i = 0; i < s.length(); i++) {
            if (freq.find(s[i]) != freq.end()) {
                int f = freq[s[i]];
                cnt[f]--;
                freq[s[i]]++;
                cnt[freq[s[i]]]++;
            } else {
                freq[s[i]] = 1;
                cnt[freq[s[i]]]++;
            }
        }
        
        int ans = 0;
        int oddnum = 0;
        
        /*
        for (auto it = freq.begin(); it != freq.end();
            ++it) {
            char c = it->first;
            cout << c << it->second << "\n";
        }
        */
        
        
        for (auto it = cnt.begin(); it != cnt.end();
            it++) {
            //cout << it->first << it->second << "\n";
            int i = it->first;
            if (it->second == 0) {
                continue;
            }
            if (i % 2 == 0) {
                ans += (i * it->second) ;
            } else {
                oddnum = 1;
                if (i != 1) {
                    ans += ((i-1) * it->second);
                }
            }
        }
        
        return ans + oddnum;
        
    }
};