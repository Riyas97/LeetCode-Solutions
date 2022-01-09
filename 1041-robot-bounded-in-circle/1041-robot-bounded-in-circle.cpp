class Solution {
public:
    bool isRobotBounded(string instructions) {
        int f1 = 0;
        int f2 = 0;
        int d = 1;
        vector <bool> v (5, false);
        
        for (int i = 0; i < instructions.size(); i++) {
            v[d] = true;
            if (instructions[i] == 'G') {
                if (d == 1) {
                    f2 += 1;
                } else if (d == 2) {
                    f1 += 1;
                } else if (d == 3) {
                    f2 -= 1;
                } else if (d == 4) {
                    f1 -= 1;
                }
            } else if (instructions[i] == 'L') {
                d -= 1;
                
                if (d < 1) {
                    d = 4;
                }
            } else {
                d += 1;
                
                if (d > 4) {
                    d = 1;
                }
            }
        }
        
        if (f1 == 0 && f2 == 0) {
            return true;
        } 
        
        if (d != 1) {
            return true;
        }

        return false;
    }
};