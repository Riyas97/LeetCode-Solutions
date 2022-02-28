class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            return {};
        }
        string str = "";
        stringstream ss;  
        ss << nums[0];  
        ss >> str; 
        int s = 0;
        
        if (nums.size() == 1) {
            return {str};
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == nums[i-1] + 1) {
                continue;
            } else {
                
                
                if (s == i-1) {
                    ans.push_back(str);
                } else {
                    string str2 = "";
                    stringstream ss;  
                    ss << nums[i-1];  
                    ss >> str2;
                    str = str + "->" + str2;
                    ans.push_back(str);
                }
                if (i != nums.size()) {
                    string str1 = "";
                    stringstream ss;  
                    ss << nums[i];  
                    ss >> str1;   
                    
                    s = i;
                    str = str1;
                    
                }
                
            }
        }
        return ans;
    }
};