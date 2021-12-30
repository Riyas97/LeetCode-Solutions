class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector <int> v1 (26, 0);
        vector <int> v2 (26, 0);
        
        for (int i = 0; i < word1.length(); i++) {
            v1[word1[i] - 'a']++;
        }
        
        for (int i = 0; i < word2.length(); i++) {
            v2[word2[i] - 'a']++;
        }
        
        for (int i = 0; i <= 25; i++) {
            int diff = abs(v2[i] - v1[i]);
            if (diff > 3) {
                return false;
            }
        }
        return true;
    }
};