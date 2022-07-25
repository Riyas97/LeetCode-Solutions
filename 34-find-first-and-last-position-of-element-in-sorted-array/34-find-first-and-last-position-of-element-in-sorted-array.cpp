class Solution {
public:
    
    int findLast(vector<int>& nums, int s, int e, int target) {
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            cout << mid << " ";
            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
        
    }
    
    int findFirst(vector<int>& nums, int s, int e, int target) {
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        
        int s = 0;
        int e = nums.size() - 1;
        
        int a = findFirst(nums, s, e, target);
        int b = findLast(nums, s, e, target);
        
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};