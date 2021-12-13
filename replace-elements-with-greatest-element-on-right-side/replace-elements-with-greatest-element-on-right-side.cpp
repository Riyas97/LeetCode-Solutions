class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans (arr.size(), -1);
        
        int a = arr[arr.size() - 1];
        
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i] > a) {
                a = arr[i];
            }    
            ans[i-1] = a;
            
        }
        return ans;
    }
};