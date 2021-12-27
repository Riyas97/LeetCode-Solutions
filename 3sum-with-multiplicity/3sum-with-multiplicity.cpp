class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int num = target - arr[i];
            int s = i + 1;
            int e = arr.size() - 1;
            
            while (s < e) {
                int sum = arr[s] + arr[e];
                
                if (sum == num) {
                    int val = 1;
                    
                    if (arr[s] == arr[e]) {
                        while (s != e) {
                            ans += (e - s);
                            s += 1;
                        }
                        break;
                    } else {
                        
                        //cout << arr[i] << arr[s] << 
                        //arr[e] << " ";
                        
                        while (s < e) {
                            if (arr[s] == arr[s+1]) {
                                val += 1;
                                s += 1;
                            } else {
                                break;
                            }
                        }

                        s += 1;
                        ans += val;
                        
                        while (e > s) {
                            if (arr[e] == arr[e-1]) {
                                ans += val;
                                e -= 1;
                            } else {
                                break;
                            }
                        }
                        e -= 1;
                        
                        //cout << ans << "\n";
                    }
                } else if (sum < num) {
                    s++;
                } else {
                    e--;
                }
            }
            
        }
        ans %= MOD;
        return int (ans);
    }
};