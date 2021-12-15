class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int s = 0;
        
        while (s < bits.size()) {
            if (bits[s] == 0) {
                if (s == bits.size() - 1) {
                    return true;
                }
                s += 1;
            } else {
                s += 2;
            }
            cout << s;
        }
        
       
        return false;
    }
};