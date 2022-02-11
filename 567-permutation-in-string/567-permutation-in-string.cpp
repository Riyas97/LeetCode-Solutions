class Solution {
public:
    bool ispermute(int l, int r, string a, string s1) {
        // Base case
        if (l == r) {
            cout << a << "\n";
            if (a == s1) {
                return true;
            } else {
                return false;
            }
        } else {
            // Permutations made
            for (int i = l; i <= r; i++) {
                // Swapping done
                char temp = a[l];
                a[l] = a[i];
                a[i] = temp;

                // Recursion called
                if (ispermute(l+1, r, a, s1)) {
                    return true;
                }

                //backtrack
                a[i] = a[l];
                a[l] = temp;
            }
        }
        return false;
    }
    
    bool isCheck(vector<int>& c1, vector<int>& c2) {
        for (int i = 0; i <= 25; i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if (s2.length() < s1.length()) {
            return false;
        }
        
        int m = s1.length();
        vector<int> c1 (26, 0);
        vector<int> c2 (26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            c1[s1[i] - 'a']++;
        }
        
        for (int i = 0; i < m - 1; i++) {
            c2[s2[i] - 'a']++;
        }
        
        int en = m - 1;
        for (int i = 0; i <= s2.length() - m; i++) {
            //cout << i;
            if (i != 0) {
                c2[s2[i - 1] - 'a']--;
            }
            
            c2[s2[en] - 'a']++;
            //cout << "pk1";
            
            if (isCheck(c1, c2)) {
                return true;
            }
            
            en++;
            
            //string choose = s2.substr(i, m);
            //if (ispermute(0, choose.length() - 1, choose, s1)) {
            //    return true;
            //}
        }
        return false;
    }
};