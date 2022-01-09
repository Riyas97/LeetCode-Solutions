class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        if (nums.size() < 4) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            for (int j = i+1; j <= nums.size() - 3; j++) {
                
                if (j != i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                int s1 = nums[i] + nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                int left = target - s1;
                
                while (l < r && l <= nums.size() - 2 && r > j) {
                    int s2 = nums[l] + nums[r];
                    
                    if (s2 == left) {
                        int count = 1;
                        vector<int> v1 = {nums[i], nums[j], nums[l], 
                                         nums[r]};
                        ans.push_back(v1);
                        
                        if (nums[l] == nums[r]) {
                            break;
                            
                        } else {
                           
                            while (l < r && nums[l+1] == nums[l]) {
                                l++;
                            }
            
                            while (r > l && nums[r-1] == nums[r]) {
                                r--;
                            }
                        }
                        
                        l++;
                        r--;
                    } else if (s2 < left) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
        
    }
};