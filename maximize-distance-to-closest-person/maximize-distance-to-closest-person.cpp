class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int a = 0;
        
        
        
        int f = -1;
        //int s = -1;
        
        //vector <int> v(seats.size(), seats.size() - 1);
        
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (f == -1) {
                    f = i;
                    
                    int m = i - 0;
                    
                    if (m > a) {
                        a = m;
                    }
                    
                } else {
                    int m = i - f;
                    m /= 2;
                    
                    if (m > a) {
                        a = m;
                    }
                    
                    f = i;
                }
            }
        }
        int m = seats.size() - 1 - f;
                   
        if (m > a) {
            a = m;
        }
        
        return a;

    }
};