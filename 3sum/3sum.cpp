class Solution {
public:
    
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set <int> us;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (us.find(nums[i]) != us.end()) {
                continue;
            }
            
            int look = 0 - nums[i];
            int s = i+1;
            int e = nums.size() - 1;
            
            while (s < e) {
                if (nums[s] + nums[e] == look) {
                    vector <int> ans1;
                    //cout << i << " " << s << " " << e << " ";
                    us.insert(nums[i]);
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[s]);
                    ans1.push_back(nums[e]);
                    ans.push_back(ans1);
                    
                    while (s != nums.size() -2 && 
                           nums[s+1] == nums[s]) {
                        s += 1;
                    }
                    
                    while (e != 1 && 
                           nums[e-1] == nums[e]) {
                        e -= 1;
                    }
                    
                    s += 1;
                    e -= 1;
                } else if (nums[s] + nums[e] > look) {
                    e -= 1;
                } else {
                    s += 1;
                }
            }
        }
        
        return ans;
    }
};




/*
class Solution {
public:
    void ts(int t, vector<vector<int>>& ans, int k, 
            vector<int>& nums) {
        unordered_set <int> us;
        for (int i = k + 1; i < nums.size(); i++) { 
            
            int tt = t - nums[i];
            if (us.find(tt) != us.end()) {
                vector<int> ans1;
                ans1.push_back(nums[k]);
                ans1.push_back(tt);
                ans1.push_back(nums[i]);
                rep[]
                ans.push_back(ans1);
            }
            us.insert(nums[i]);
        }
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map <int, int> rep;
        
        for (int i = 0; i < nums.size(); i++) {
            int t = 0 - nums[i];
            ts(t, ans, i, nums);
        }
        return ans;
    }
};


*/