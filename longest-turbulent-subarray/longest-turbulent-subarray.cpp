class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector <int> v (arr.size(), 2);
        
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i+1]) {
                v[i] = 0;
            } else if (arr[i] > arr[i+1]) {
                v[i] = 1;
            }
        }
        
        int ans = 0;
        int st = 0;
        int stA = v[st];
        
        for (int i = 1; i < arr.size(); i++) { 
            if (stA == 1 - v[i]) {
                stA = v[i];
                cout << i << " ";
            } else {
                if (v[i-1] == 2) {
                    ans = max(ans, i - st);   
                } else {
                    ans = max(ans, i - st + 1);
                }
                st = i;
                stA = v[i];
            }
        
        }
        int last = arr.size() - st;
        if (last > ans) {
            return last;
        }
        return ans;
            
    }
};