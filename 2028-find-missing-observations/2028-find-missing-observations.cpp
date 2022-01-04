class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m + n) * mean;
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        int diff = total - sum;
        cout << sum << " " << diff << "\n";
        vector <int> vect;
        if (diff > n * 6 || diff < n * 1) {
            return vect;
        }
        int st = 1 * n;
        vect.resize(n, 1);
        vect[0] = 1 + (diff - st);
        
        for (int i = 0; i < n - 1; i++) {
            if (vect[i] > 6) {
                vect[i+1] = vect[i] - 6 + vect[i+1];
                vect[i] = 6;
            } else {
                break;
            }
        }
        return vect;
    }
};