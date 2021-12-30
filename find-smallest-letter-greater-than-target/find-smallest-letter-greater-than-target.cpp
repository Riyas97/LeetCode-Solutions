class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0;
        int e = letters.size() - 1;
        int c = letters.size() - 1;
        
        if (target >= letters[letters.size() - 1]) {
            return letters[0];
        }
        
        while (s <= e) {
            if (s < 0 || e > letters.size() - 1) {
                break;
            }
            int m = (s + e) / 2;
            if (letters[m] == target) {
                s = m + 1;
            } else {
                if (letters[m] < target) {
                    s = m + 1;
                } else {
                    c = min(m, c);
                    e = m - 1;
                }
                
                if (s < 0 && letters[letters.size() - 1] < target) {
                    return letters[0];
                } 
                if (e > letters.size() - 1 && letters[0] < target) {
                    return letters[letters.size() - 1];
                }
            }
        }
        return letters[c];
    }
};