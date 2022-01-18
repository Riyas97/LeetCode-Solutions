class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> vect;
        
        if (k > nums.size()) {
            k = k % nums.size();
        }
        
        for (int i = 0; i < nums.size(); i += 1) {
            vect.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i += 1) {
            nums[i] = vect[(vect.size() - k + i) % vect.size()];
        }
        
        
        /*
        for (int i = 0; i < k; i += 1) {
            nums.insert(nums.begin(), nums[nums.size() - 1]);
            nums.pop_back();
        }
        */
    
    }
};