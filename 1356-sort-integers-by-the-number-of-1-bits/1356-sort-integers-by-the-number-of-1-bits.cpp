class Solution {
public:
    int count(int num) {
        int ans = 0;
        while (num > 0) {
            if (num == 2) {
                ans++;
                break;
            }
            if (num == 1) {
                ans++;
                break;
            }
            
            if (num % 2 == 1) {
                ans++;
            }
            num /= 2;
        }
        return ans;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this] 
             (int a, int b) {
                 int na = count(a);
                 int nb = count(b);
                 if (na == nb) {
                     return a < b;
                 } 
                 return na < nb;
             }
            );
        return arr;
    }
};