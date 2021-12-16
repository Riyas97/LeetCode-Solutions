class Solution {
public:
    bool canConstruct(string ran, string mag) {
        vector <int> ma (26, 0);
        
        for (int i = 0; i < mag.size(); i++) {
            ma[mag[i] - 'a']++;
        }
        
        for (int i = 0; i < ran.size(); i++) {
            if (ma[ran[i] - 'a'] == 0) {
                return false;
            } else {
                ma[ran[i] - 'a'] -= 1;
            }
        }
        return true;
    }
};