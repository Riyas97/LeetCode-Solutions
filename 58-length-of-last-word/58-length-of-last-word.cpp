class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss (s);
        string temp;
        int ans = 0;
        
        while (getline(ss, temp, ' ')) {
        // Concatenating in the string
        // to be returned
            //cout << temp << "\n";
            if (temp.length() != 0) {
                ans = temp.length();
            }
        }
        
        return ans;
    }
};