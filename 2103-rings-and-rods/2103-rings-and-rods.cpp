class Solution {
public:
    int countPoints(string rings) {
        vector <bool> red(10, false);
        vector <bool> green(10, false);
        vector <bool> blue(10, false);
        
        for (int i = 0; i <= rings.size() - 2; i += 2) {
            //cout << i;
            char lett = rings[i];
            int rod = rings[i+1] - '0';
            if (lett == 'R') {
                red[rod] = true;
            } else if (lett == 'G') {
                green[rod] = true;
            } else {
                blue[rod] = true;
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            if (red[i] && green[i] && blue[i]) {
                ans++;
            }
        }
        return ans;
    }
};