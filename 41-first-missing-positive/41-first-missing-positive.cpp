class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                int now = nums[i];
                int ind = i;
                if (now == i+1) {
                    continue;
                } 
                
                nums[ind] = -1;
                
                while (true) {
                    //cout << i << now << " ";
                    
                    if (now > nums.size() || now <= 0) {
                        break;
                    }
                    
                    if (nums[now-1] == now) {
                        break;
                    }
                    
                    int tmp = nums[now-1];
                    nums[now-1] = now;
                    now = tmp;
                    
                }
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};