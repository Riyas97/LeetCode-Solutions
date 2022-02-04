class Solution {
public:
    int dp(vector<int>& arr, int k, int ind,
           vector <int>& maxhere) {
        if (ind == arr.size() - 1) {
            return arr[ind];
        }
        
        if (ind > arr.size() - 1) {
            return 0;
        }
        
        if (maxhere[ind] != -1) {
            return maxhere[ind];
        }
        
        
        //cout << "ind is " << ind << " " << sofar << " "
        //    << ans << "\n";
        int msum = arr[ind];
        int val = arr[ind];
        for (int i = ind; i < ind + k; i++) {
            if (i >= arr.size()) {
                break;
            }
            msum = max(msum, arr[i]);
            int thisval = (i - ind + 1) * msum + 
                dp(arr, k, i+1, maxhere);
            val = max(val, thisval);
        }
        
        //cout << "ind is " << ind << " " << sofar << " "
        //    << ans << "\n";
        
        //maxhere[ind] = ans-init;
        maxhere[ind] = val;
        return maxhere[ind];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int ans = 0;
        int sofar = 0;
        vector <int> maxhere(arr.size(), -1);
        maxhere[arr.size() - 1] = arr[arr.size() - 1];
        return dp(arr, k, 0, maxhere);
    }
};


/*
class Solution {
public:
    int dp(vector<int>& arr, int k, int ind, int& sofar, 
           int& ans, vector <int>& maxhere) {
        if (ind == arr.size()) {
            cout << sofar << "se\n";
            ans = max(ans, sofar);
            return;
        }
        
        if (maxhere[ind] != -1) {
            cout << sofar << "sj\n";
            ans = max(ans, sofar + maxhere[ind]);
            return;
        }
        
        //cout << "ind is " << ind << " " << sofar << " "
        //    << ans << "\n";
        int msum = arr[ind];
        int val = arr[ind];
        int init = ans;
        for (int i = ind; i < ind + k; i++) {
            if (i >= arr.size()) {
                break;
            }
            msum = max(msum, arr[i]);
            sofar += (i - ind + 1) * msum;
            val = max(val, (i - ind + 1) * msum);
            dp(arr, k, i+1, sofar, ans, maxhere);
            sofar -= (i - ind + 1) * msum;
        }
        
        //cout << "ind is " << ind << " " << sofar << " "
        //    << ans << "\n";
        
        //maxhere[ind] = ans-init;
        return;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int ans = 0;
        int sofar = 0;
        vector <int> maxhere(arr.size(), -1);
        maxhere[arr.size() - 1] = arr[arr.size() - 1];
        return dp(arr, k, 0, sofar, ans, maxhere);
        for (int i = 0; i < arr.size(); i++) {
            //cout << maxhere[i] << " ";
        }
        return ans;
    }
};

*/