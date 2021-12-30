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
            vect.push_back(can[i]);
            sum += can[i];
            backtrack(target, ans, can, vect, sum, i);
            sum -= can[i];
            vect.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vect;
        int sum = 0;
        backtrack(target, ans, candidates, vect, sum, 0);
        return ans;
    }
};