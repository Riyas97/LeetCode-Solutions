class Solution {
public:
    string getHint(string secret, string guess) {
        vector <int> c1 (10, 0);
        vector <int> c2 (10, 0);
        int i = 0;
        int bulls = 0;
        int cows = 0;
        
        while (i <= guess.length() - 1) {
            int a1 = secret[i] - '0';
            int a2 = guess[i] - '0';
            //cout << a1 << a2;
            if (a1 == a2) {
                bulls++;
            } else {
                c1[a1]++;
                c2[a2]++;
            }
            i++;
        }
        
        for (int i = 0; i <= 9; i++) {
            if (c1[i] > 0) {
                cows += min(c1[i], c2[i]);
            }
        }
        
        string b = to_string(bulls);
        string c = to_string(cows);
        return b + 'A' + c + 'B';
    }
};