class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        typedef tuple <int, int> comp;
        vector <comp> vect;
        vector <int> ans;
        if (nums.size() < k) {
            return ans;
        } else if (nums.size() == k) {
            return nums;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            vect.push_back(make_tuple(nums[i], i));
        }
        sort(vect.begin(), vect.end(), [this] 
             (comp a, comp b) {
                 int n1 = get<0>(a);
                 int n2 = get<0>(b);
                 if (n1 > n2) {
                     return true;
                 } 
                 return false;
             }
            );
        vector<comp> inte;
        
        for (int i = 0; i < k; i++) {
            inte.push_back(vect[i]);
        }
        
        sort(inte.begin(), inte.end(), [this] 
             (comp a, comp b) {
                 int n1 = get<1>(a);
                 int n2 = get<1>(b);
                 if (n1 < n2) {
                     return true;
                 } 
                 return false;
             }
            );
        
        for (int i = 0; i < inte.size(); i++) {
            ans.push_back(nums[get<1>(inte[i])]);
        }
        
        return ans;
    }
};