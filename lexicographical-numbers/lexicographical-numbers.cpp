class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int a = n;
        vector <int> ans;
        int f = 1;
        
        while(a--) {
            ans.push_back(f);
            
            if (f * 10 <= n) {
                f *= 10;
            } else if (f % 10 != 9 && f + 1 <= n) {
                f += 1;
            } else if (f / 10 > 0) {
                f /= 10;
                
                while (f % 10 == 9) {
                    f /= 10;
                }
                
                f += 1;
            }
            
        }
        
        cout << ans.size();
        return ans;
    }
};