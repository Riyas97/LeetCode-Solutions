class Solution {
public:
    int findlast(vector<int>& nums, int s, int e, int t) {
        int a = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == t) {
                a = m;
                s = m + 1;
            } else if (nums[m] < t) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return a;
    }
    
    int findfirst(vector<int>& nums, int s, int e, int t) {
        int a = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == t) {
                a = m;
                e = m - 1;
            } else if (nums[m] < t) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return a;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size() - 1;
        int a = findfirst(nums, s, e, target);
        int b = findlast(nums, s, e, target);
        
        vector<int> ans;
        cout << a << b;
        
        if (a == -1) {
            return ans;
        }
        
        for (int i = a; i <= b; i += 1) {
            ans.push_back(i);
        }
        return ans;

    }
};