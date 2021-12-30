class Solution {
public:
    void backtrack(int target, vector<vector<int>>& ans,
                  vector<int>& can, vector<int>& vect, int& sum,
                  int ind) {
        if (sum == target) {
            ans.push_back(vect);
            return;
        }
        
        if (sum > target) {
            return;
        }
        
        for (int i = ind; i < can.size(); i++) {
            if (i != 0 && can[i] == can[i-1]) {
                continue;
            }
            vect.push_back(can[i]);
            sum += can[i];
            
            int ind = i + 1;
            
            while (ind <= can.size() - 1 && 
                   can[ind] == can[i]) {
                ind += 1;
            }
            
            int rep = ind - i - 1;
            //cout << rep;
            
            if (rep > 0) {
                //cout << rep << "-" << ind << "\n";
                //if (can[i] == 3) {
                //    cout << rep;
                //}
                vector<int> v2 = vect;
                int sum1 = sum;
                for (int j = 0; j < rep; j++) {
                    v2.push_back(can[i]);
                    sum1 += can[i];
                    
                    //if (can[i] == 3) {
                    //    cout << sum1;
                    //}
                    
                    backtrack(target, ans, can, v2, sum1, ind);
                }    
            }
            
            backtrack(target, ans, can, vect, sum, ind);
                
            sum -= can[i];
            vect.pop_back();     
            
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //unordered_map <int, int> m;
        //for (int i = 0; i < candidates.size(); i++) {
        //    m[candidates[i]] = i;
        //}
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> vect;
        int sum = 0;
        backtrack(target, ans, candidates, vect, sum, 0);
        return ans;
    }
};