class Solution {
public:
    string sortSentence(string s) {
        vector <string> vect(10, "");
        
        stringstream ss (s);
        string temp;
        int count = 0;
        
        while (getline(ss, temp, ' ')) {
            count++;
            int num = temp[temp.length() - 1] - '0';
            vect[num-1] = temp.substr(0, temp.length() - 1);
        }
        
        string ans = "";
        
        for (int i = 0; i < count; i++) {
            ans += vect[i];
            if (i != count - 1) {
                ans += " ";
            }
        }
        
        return ans;
        
    }
};