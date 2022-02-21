class Solution {
public:
    /*
    dababbc
    
    ababb
    
    */
    
    bool ismatch(vector<int>& vect, int k) {
        for (int i = 0; i <= 25; i++) {
            if (vect[i] != 0 && vect[i] < k) {
                return false;
            }
        }
        return true;
    }
    
    int longestSubstring(string s, int k) {
        
        int dcount = 0;
        vector<int> count (26, 0);
        for (int i = 0; i < s.length(); i++) { 
            //cout << i;
            count[s[i]-'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] >= k) {
                dcount++;
            }
        }
        
        //cout << "dcount is: " << dcount << "\n";
        
        int ans  = 0;
        for (int a = 1; a <= dcount; a++) {
            //cout << "dount " << a << "\n";
            int tcount = 0;
            unordered_set<char> k1;
            vector<int> k2(26, 0);
            int st = 0;
            
            for (int i = 0; i < s.length(); i++) {
                if (k1.find(s[i]) != k1.end()) {
                    k2[s[i] - 'a']++;
                } else {
                    if (tcount < a) {
                        tcount++;
                        k1.insert(s[i]);
                        k2[s[i] - 'a']++;
                    } else {
                        
                        if (ismatch(k2, k)) {
                            ans = max(ans, i-st);
                            //cout << "ans here is: " << ans << "\n";
                        }
                        
                        while(st < i && tcount == a) {
                            k2[s[st]-'a']--;
                            if (k2[s[st]-'a'] == 0) {
                                k1.erase(s[st]);
                                tcount--;
                            }
                            st++;
                        }
                        
                        tcount++;
                        k1.insert(s[i]);
                        k2[s[i] - 'a']++;
                    
                    }
                }
            }
            
            if (ismatch(k2, k)) {
                int n = s.length();
                ans = max(ans, n-st);
                //cout << "ans here is: " << ans << "\n";
            }
            
        }
        
        return ans;
    }
};