class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> ans (index.size(), -1);
        for (int i = 0; i < index.size(); i++) {
            if (ans[index[i]] == -1) {
                ans[index[i]] = nums[i];    
            } else {
                int insert = nums[i];
                int en = index[i];
                while (en <= nums.size() - 1 && 
                       ans[en] != -1) {
                    cout << en << " ";
                    int temp = ans[en];
                    ans[en] = insert;
                    insert = temp;
                    en++;
                }
                if (ans[en] == -1) {
                    ans[en] = insert;
                }
            
            }
            
        }
        return ans;
    }
};