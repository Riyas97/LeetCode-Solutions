class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map <int, int> um;
        unordered_map <int, tuple<int,int>> se;
        int freq = 1;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            freq = max(freq, um[nums[i]]);
            if (se.find(nums[i]) == se.end()) {
                tuple<int,int> tu = make_tuple(i, i); 
                se[nums[i]] = tu;
            } else {
                int st = get<0>(se[nums[i]]);
                tuple<int,int> tu = make_tuple(st, i); 
                se[nums[i]] = tu;
            }
        }
        
        if (freq == 1) {
            return 1;
        }
        
        int sdiff = INT_MAX;
        for (auto it = se.begin(); it != se.end(); it++) {
            int num = it->first;
            if (um[num] != freq) {
                continue;
            }
            tuple<int,int> tu = it->second;
            int diff = get<1>(tu) - get<0>(tu) + 1;
            sdiff = min(sdiff, diff);
        }
        return sdiff;
        
    }
};