class Solution {
public:
    bool dp(int ind, vector<int>& nums,
          vector<int>& minStep) {
        if (ind >= nums.size() - 1) {
            return true;
        }
        
        if (minStep[ind] != -1) {
            return true;
        }
        
        if (nums[ind] == 0) {
            return false;
        }
        
        int minNum = nums.size();
        
        for (int i = 1; i <= nums[ind]; i++) {
            //cout << ind << i << " ";
            if (ind + i >= nums.size() - 1) {
                minNum = min(minNum, 1);
            } else if (dp(ind + i, nums, minStep)) {
                //cout << ind << i << minStep[ind+i] << " ";
                minNum = min(minNum, 1 + minStep[ind+i]);
            }
        }
        
        minStep[ind] = minNum;
        
        return true;
        
    }
    
    int jump(vector<int>& nums) {
        vector <int> minStep (nums.size(), -1);
        minStep[minStep.size() - 1] = 0;
        bool status = dp(0, nums, minStep);
        //cout << minStep[1] << minStep[2] << minStep[3] << minStep[4];
        return minStep[0];
    }
};