class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> v1;
        
        for (int i = 0; i < nums.size(); i++) {
            v1.push_back(to_string(nums[i]));
        }
        
        sort(v1.begin(), v1.end(), [this] 
             (string a, string b) {
                 string c1 = a + b;
                 string c2 = b + a;
                 
                 if (c1 > c2) {
                     //cout << c1 << c2 << " ";
                     return true;
                 } 
                 //cout << c1 << " " << c2 << "\n";
                 return false;
             }
            );
        
        for (int i = 0; i < v1.size(); i++) {
            
            if (i == 0 && v1[i] == "0") {
                ans += '0';
                return ans;
            }
            ans += v1[i];
        }
        
        return ans;
    }
};