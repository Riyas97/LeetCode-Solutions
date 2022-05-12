class Solution {
public:
    void permute(vector<vector<int>>& results, 
                unordered_map<int,int>& counter,
                 vector<int>& store, int len) {
        if (store.size() == len) {
            results.push_back(store);
            return;
        }
        for (auto it = counter.begin();
            it != counter.end(); it++) {
            int key = it->first;
            int val = it->second;
            if (val == 0) {
                continue;
            }
            store.push_back(key);
            counter[key]--;
            permute(results, counter, store, len);
            counter[key]++;
            store.pop_back();
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int,int> counter;
        vector<int> store;
        for (int i = 0; i < nums.size(); i++) {
            counter[nums[i]]++;
        }
        permute(results, counter, store, nums.size());
        return results;
    }
};