class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector <long long> forw (arr.size(), 0);
        vector <long long> backw (arr.size(), 0);
        unordered_map <int, long long> count;
        unordered_map <int, long long> count2;
        
        for (int i = 0; i < arr.size(); i++) {
            if (count.find(arr[i]) != count.end()) {
                forw[i] = (count[arr[i]] * i) - 
                    count2[arr[i]];
                //cout << i << " " << count[arr[i]] << "\n";
            } 
            count[arr[i]]++;
            count2[arr[i]] += i; ;
        }
        
        count.clear();
        count2.clear();
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (count.find(arr[i]) != count.end()) {
                backw[i] = count2[arr[i]] - 
                    (count[arr[i]] * i);
                //cout << count[arr[i]];
            } 
            count[arr[i]]++;
            count2[arr[i]] += i; ;
        }
        
        vector <long long> ans (arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) { 
            cout << forw[i] << backw[i] << "\n";
            ans[i] += forw[i];
            ans[i] += backw[i];
        }
        return ans;
    }
};